#include "face_detect.h"

Face_Detect::Face_Detect()
{
//    cout<<"0"<<endl;
    imgPath="D:/桌面/jm/4.wj.jpg";
    requestUrl = "https://aip.baidubce.com/rest/2.0/face/v3/search";//
    //这里更换为自己的Access Token,每个Access Token的有效期为30天
    accessToken = "24.3b39e69d51bac4586663c2b9c3e3f992.2592000.1679187737.282335-30484189";
    imgPath = "";
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
}


void Face_Detect::run()
{
    //设置请求地址
    QUrl url(requestUrl + "?access_token=" + accessToken);
    QNetworkRequest request(url);

    //设置数据提交格式，这个不能自己随便写，每个平台的格式可能不一样，百度AI要求的格式为application/json
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));

    //将要检测的图片进行BASE64编码
    QImage image(imgPath);
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

void Face_Detect::replyFinished(QNetworkReply *reply)
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
//                QJsonArray user_list = resultObj.take("user_list").toArray();
//                qDebug()<<"user_list:"<<user_list<<endl;
//                QString groupid = user_list.at(0).toObject().take("group_id").toString();
//                QString user_id = user_list.at(0).toObject().take("user_id").toString();
//                //double Score = user_list.at(0).toObject().take("score").toDouble();
//                ui->label_2->setText(user_id);
//                ui->label_4->setText(groupid);
//                //ui->label_6->setText(Score);
            }
        }
    }
    reply->deleteLater();
}
