#include "widget.h"
#include "ui_widget.h"


#include <QFile>
#include <QMessageBox>
#include<QPixmap>



Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->initform();

}

Widget::~Widget()
{
    delete ui;
}
//主界面初始化
void Widget::initform()
{

    ui->label_titile->setText("智能家居小助手");
    setFixedSize(this->width(), this->height());//禁止调节窗口大小
    this->setWindowTitle(tr("智能家居小助手"));//设置窗口名称
    ui->stackedWidget->setCurrentWidget(ui->page_2);

    manager = new QNetworkAccessManager(this);  //新建QNetworkAccessManager对象
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(reply(QNetworkReply*)));//关联信号和槽

    //界面图标
    this->LoadStyleSheet(":/QSS/style.css");//加载qss
    qDebug()<<"233333333"<<endl;
    setToolButtonStyle(ui->tbnSetting,"设置",0,":/icon/setting.png");
    setToolButtonStyle(ui->tbnHome,"首页",0,":/icon/zhuye.png");
    setToolButtonStyle(ui->tbnControl,"家居控制",0,":/icon/control.png");
    setToolButtonStyle(ui->tbnStatistic,"数据统计",0,":/icon/static.png");
    setToolButtonStyle(ui->tbnWeather,"天气情况",0,":/icon/sum.png");
    setToolButtonStyle(ui->tbnSelect,"模式选择",0,":/icon/api.png");

    setToolButtonStyle(ui->tbnParlor,"客厅",1,":/icon/keting.png");
    setToolButtonStyle(ui->tbnBedRoom,"卧室",1,":/icon/wos.png");
    setToolButtonStyle(ui->tbnKitchen,"厨房",1,":/icon/chuf.png");
    setToolButtonStyle(ui->tbnSafety,"浴室",1,":/icon/yus.png");


    this->initDataTime();
    this->initweather();
    this->initparlor();
    this->initkitchen();
    this->initbedroom();
    this->initchart();
    this->initsetting();

}
//时间设置
void Widget::initDataTime()
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), SLOT(time_update()));
    timer->start(1000); //1s执行一次,定时器
}
void Widget::time_update(void)
{
    QDateTime time = QDateTime::currentDateTime();
    //QString str = time.toString("yyyy-MM-dd hh:mm:ss ddd");
    ui->label_hour->setText(time.toString("hh"));
    ui->label_min->setText(time.toString("mm"));
    ui->label_sec->setText(time.toString("ss"));
    ui->label_data->setText(time.toString("yyyy年MM月dd日"));
    ui->label_week->setText(time.toString("ddd"));
}


//读取qss文件
bool Widget::LoadStyleSheet(const QString &StyleSheetFile)
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

//设置ToolButton图标
void Widget::setToolButtonStyle(QToolButton *tbn, const QString &text,int textSize,const QString iconName)
{
    //设置显示的文本
    tbn->setText(text);
    if (textSize == 1)
    {
        tbn->setFont(QFont("文泉驿雅黑",16,QFont::Bold));
    }else if (textSize == 0)
        tbn->setFont(QFont("文泉驿雅黑",11,QFont::Bold));

    tbn->setAutoRaise(true);
    //设置按钮图标
    tbn->setIcon(QPixmap(QString("%1").arg(iconName)));
    tbn->setIconSize(QPixmap(QString("%1").arg(iconName)).size());
    //设置文本在图标下边
    tbn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
}

void Widget::reply(QNetworkReply *reply)
{
    qDebug()<<"finish!!";

    //QTextCodec *codec = QTextCodec::codecForName("utf8");
    QString all = reply->readAll();//codec->toUnicode().toLocal8Bit();
    QJsonParseError err;
    QJsonDocument json_recv = QJsonDocument::fromJson(all.toUtf8(),&err);

    qDebug() << err.error;

    if(!json_recv.isNull())
    {
        QJsonObject object = json_recv.object();
        qDebug()<<object<<endl;
        QJsonObject dataValue = object.value(QStringLiteral("data")).toObject();

        QString loc = dataValue["address"].toString();                   //位置
        QString weather=dataValue["weather"].toString();                 //天气
        QString temp = dataValue["temp"].toString();                     //温度
        QString humidity=dataValue["humidity"].toString();               //湿度
        QString windDirection=dataValue["windDirection"].toString();     //风向
        QString windPower=windDirection+" "+dataValue["windPower"].toString();             //风力
        ui->label_city->setText("如皋市");
        ui->label_temp->setText(temp);
        ui->label_weather_2->setText(weather);
        ui->label_4->setText(humidity);
        ui->label_2->setText(windPower);


    }
    else
    {
        qDebug()<<"json_recv is NULL or is not a object !!";
    }
    reply->deleteLater();
}


//首页跳转函数
void Widget::on_tbnHome_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_2);
}

//家居控制跳转函数
void Widget::on_tbnControl_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page);
}

//天气界面跳转函数
void Widget::on_tbnWeather_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_3);
}

//客厅界面跳转函数
void Widget::on_tbnParlor_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->parlor);
}

//卧室界面跳转函数
void Widget::on_tbnBedRoom_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->bedroom);
    QTimer *mTime = new QTimer();
    connect(mTime,&QTimer::timeout,this,[=]()
    {
        //update();	//定时处理内容
        m_tcp->write("get_evr");
    });
    mTime->start(5000);


}

//厨房界面跳转函数
void Widget::on_tbnKitchen_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->kitchen);
}

//浴室界面跳转函数
void Widget::on_tbnSafety_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->bathroom);
}

