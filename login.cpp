#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);


    user=new Widget;//用户界面对象
    timer = new QTimer(this);//进度条定时器
    ui->stackedWidget_login->setCurrentWidget(ui->page_3);
    this->setWindowIcon(QIcon(":/icon/AI.png"));// 可执行程序图标
    this->LoadStyleSheet(":/QSS/style.css");//加载qss
    setFixedSize(this->width(), this->height());//禁止调节窗口大小
    this->setWindowTitle(tr("智能家居小助手"));//设置窗口名称
    ui->open_btn->setIcon(QIcon(":/icon/camera.png"));
    ui->open_btn->setLayoutDirection(Qt::LeftToRight);
    ui->paizhao_btn->setIcon(QIcon(":/icon/paizhao.png"));
    ui->paizhao_btn->setLayoutDirection(Qt::LeftToRight);
    ui->enter_btn->setIcon(QIcon(":/icon/jiantou.png"));

    camera = new QCamera(this);
    viewfinder=new QCameraViewfinder(ui->camera_label);
    CamerimageCapture=new QCameraImageCapture(camera);

    //设置采集模式
    CamerimageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
    camera->setCaptureMode(QCamera::CaptureStillImage);//将其采集为图片
    camera->setCaptureMode(QCamera::CaptureMode::CaptureViewfinder);//将采集到取景器中

    camera->setViewfinder(viewfinder);
    camera->start();
    connect(CamerimageCapture, SIGNAL(imageCaptured(int,QImage)), this, SLOT(displayImage(int,QImage)));
    connect(timer, SIGNAL(timeout()), this, SLOT(timeoutslots()));//进度条定时器

    //////////////
    requestUrl = "https://aip.baidubce.com/rest/2.0/face/v3/search";//
    //requestUrl = "https://aip.baidubce.com/rest/2.0/face/v3/detect";
    //Access Token,每个Access Token的有效期为30天
    accessToken = "24.e887339dc631cc2f1e81f105a3278801.2592000.1683381154.282335-32076059";

    imgPath="D:/桌面/jm/4.wj.jpg";
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
    connect(timer, SIGNAL(timeout()), this, SLOT(timeoutslots()));

}

Login::~Login()
{
    delete ui;
}

void Login::on_enter_btn_clicked()//跳转
{
    user->show();
    this->close();//销毁
}

//读取qss文件
bool Login::LoadStyleSheet(const QString &StyleSheetFile)
{
    QFile ofile(StyleSheetFile);
    bool Ret = ofile.open(QFile::ReadOnly);

    if (!Ret)
    {
         QMessageBox::information(this,"Tip",ofile.errorString());
         return false;
    }

    this->setStyleSheet(ofile.readAll());
    ofile.close();

    return true;
}

QString Login::image2base64_str(const QImage &img)
{
    QByteArray data;
    QBuffer buf(&data);
    buf.open(QIODevice::WriteOnly);
    img.save(&buf, "BMP");
    QString b64str = QString(data.toBase64());
    return b64str;
}

void Login::timeoutslots()
{
    int index = ui->progressBar->value();
    index++;
    if (index > 100)
    {
        timer->stop();
        ui->group_label_2->setText(user_id);
        ui->group_label->setText(groupid);
        ui->group_label_2->setText("wj");
        ui->group_label->setText("user");
        return;
    }
    ui->progressBar->setValue(index);
    //先获取进度条的值，并增加
    //如果大于100，不用执行
    //未大于100，将增加后的值重新赋值。
}

void Login::on_main_btn_clicked()//跳转
{
    ui->stackedWidget_login->setCurrentWidget(ui->page_3);
}

void Login::on_face_btn_clicked()//跳转至人脸录入
{
    ui->stackedWidget_login->setCurrentWidget(ui->page_4);
}


void Login::displayImage(int , QImage image)
{
    ui->camera_label_2->setPixmap(QPixmap::fromImage(image));
}


void Login::on_paizhao_btn_clicked()//拍照并上传百度AI
{
    //    //绝对路径********
    //    CamerimageCapture->capture("D://Programmingtools//QT//project//SmartHomeAssistant//capture");
    //    upload=new Face_Detect;
    //    upload->start();
    timer->start(21);

    QString path = QDir::currentPath();//获取当前工程目录
    path+="/capture/1";
    CamerimageCapture->capture(path);//保存的位置re
    //设置请求地址
    QUrl url(requestUrl + "?access_token=" + accessToken);
    QNetworkRequest request(url);

    //设置数据提交格式，这个不能自己随便写，每个平台的格式可能不一样，百度AI要求的格式为application/json
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));

    //将要检测的图片进行BASE64编码
    imgPath=path+".jpg";
    QImage image(imgPath);
    qDebug()<<"imgpath:"<<imgPath<<endl;

    QByteArray ba;
    QBuffer buffer(&ba);
    buffer.open(QIODevice::WriteOnly);
    //以png格式将图片数据写入ba
    image.save(&buffer, "png");
    //将图片进行BASE64编码
    QString imgData = QString(ba.toBase64());
    buffer.close();

    //打包请求参数
    QJsonObject post_data;;
    QJsonDocument document;

    post_data.insert("image", imgData);
    post_data.insert("image_type", "BASE64");
    post_data.insert("group_id_list", "users");

    document.setObject(post_data);
    QByteArray post_param = document.toJson(QJsonDocument::Compact);

    //发送请求
    manager->post(request, post_param);
}


void Login::on_open_btn_clicked()//打开相机（无效）
{
    //camera->start();
}

void Login::replyFinished(QNetworkReply *reply)//解析json数据
{
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    if(200 != statusCode)
    {
        qDebug() << "Status code is error:" << statusCode;
        return;
    }
    replyData = reply->readAll();
    qDebug()<<"reply data is:"<<QString(replyData);

    QJsonParseError json_error;
    QJsonDocument document = QJsonDocument::fromJson(replyData, &json_error);
    if(json_error.error == QJsonParseError::NoError)
    {
        //判断是否是对象,然后开始解析数据
        if(document.isObject())
        {
            QJsonObject obj = document.object();


            //解析反馈的人脸属性结果
            if(obj.contains("result"))
            {
                QJsonObject resultObj = obj.take("result").toObject();
                qDebug() <<"resultObj:"<<resultObj<<endl;
                QJsonArray user_list = resultObj.take("user_list").toArray();
//                qDebug()<<"user_list:"<<user_list<<endl;
                groupid = user_list.at(0).toObject().take("group_id").toString();
                user_id = user_list.at(0).toObject().take("user_id").toString();
//                //double Score = user_list.at(0).toObject().take("score").toDouble();
//                ui->group_label_2->setText(user_id);
//                ui->group_label->setText(groupid);
//                //ui->label_6->setText(Score);
            }
        }
    }
    reply->deleteLater();
}

void Login::on_open_pic_btn_clicked()//人脸注册-打开图片
{
    imgPath = QFileDialog::getOpenFileName(this, tr("Open Image"),
                                           "./", tr("Image files(*.jpg *.png *.jpeg);;All files (*.*)"));
    if(imgPath.isEmpty())
    {
        QMessageBox msgBox;
        msgBox.warning(this,"警告","打开图片失败!");
        return;
    }
    else
    {
        QImage img(imgPath);
        //保持长宽比进行缩放
        img = img.scaled(ui->camera_label_3->width(), ui->camera_label_3->height(), Qt::KeepAspectRatio);
        ui->camera_label_3->setPixmap(QPixmap::fromImage(img));
    }
}

void Login::on_register_btn_clicked()//人脸注册-注册按钮
{
    //获取用户输入的姓名、组号
    QString name=ui->register_name->text();
    QString group=ui->register_group->text();
    if(!name.isEmpty() && !group.isEmpty())
    {
        //注册
        FaceRegister(QImage(imgPath), group, name);
        return;
    }
    QMessageBox::information(this,"提示","注册信息不完整！");
}

void Login::FaceRegister(QImage image, QString group_id, QString user_id)
{
    QString img_base64 = image2base64_str(image);
    //打包请求参数
    QJsonObject post_data;;
    post_data.insert("image", img_base64);
    post_data.insert("image_type", "BASE64");
    post_data.insert("group_id", group_id);
    post_data.insert("user_id", user_id);
    QJsonDocument document;
    document.setObject(post_data);
    QByteArray post_param = document.toJson(QJsonDocument::Indented);

    QUrl url(FaceAdd + "?access_token=" + accessToken);
    NetRequest.setUrl(url);
    NetRequest.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json")); //接口固定
    connect(manager,&QNetworkAccessManager::finished,this,FaceRegisterReply);
    manager->post(NetRequest,post_param);
}
void Login::FaceRegisterReply(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError)
    {
        QMessageBox::warning(0,"","请求错误！");
        return;
    }
    else
    {
        QByteArray content = reply->readAll();

        QJsonParseError jsonError;
        QJsonDocument doucment = QJsonDocument::fromJson(content, &jsonError);  // 转化为 JSON 文档
        if (!doucment.isNull() && (jsonError.error == QJsonParseError::NoError))
        {
            if (doucment.isObject())
            {
                QJsonObject root_object = doucment.object();
                if (root_object.take("error_code").toInt() == 0 && root_object.take("error_msg").toString() == "SUCCESS")
                {
                    //emit RegisterReply("人脸注册成功！\n");
                }
            }
        }
        reply->deleteLater();
    }
    //disconnect(manager,&QNetworkAccessManager::finished,this,FaceRegisterReply);
}
