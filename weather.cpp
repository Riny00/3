#include"widget.h"
#include "ui_widget.h"
#include"spider.h"

#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include<QPixmap>
#include<QDebug>
#include <QVector>
#include<QTime>

class Widget;

//天气情况初始化
void Widget::initweather()
{
    this->weather_update();
    //get_weather->waiget_weathert();


    //图片初始化
    QPixmap icon1(tr(":/icon/duoyun.png"));
    ui->label_weather_pic->setPixmap(icon1);
    ui->label_weather_pic->setFixedSize(icon1.size());
    QPixmap icon2(tr(":/icon/xibeif.png"));
    ui->label_wind_pic->setPixmap(icon2);
    ui->label_wind_pic->setFixedSize(icon2.size());
    QPixmap icon3(tr(":/icon/shidu.png"));
    ui->label_temp_pic->setPixmap(icon3);
    ui->label_temp_pic->setFixedSize(icon3.size());
    QPixmap icon4(tr(":/icon/qiqya.png"));
    ui->label_pressure_pic->setPixmap(icon4);
    ui->label_pressure_pic->setFixedSize(icon4.size());

    //接收子线程发的信号
    connect(get_weather,&spider::sendtomain,this,[=](QVector<QString> list)
    {
        //qDebug()<<"接收！！！"<<endl;
       weather_list_main = list;
       ui->label_weather_2->setText(weather_list_main[0]);//天气
       ui->label_temp->setText(weather_list_main[1]+"°");//温度
       ui->label_2->setText(weather_list_main[2]);//风向
       ui->label_5->setText(weather_list_main[3]);//气压
       ui->label_4->setText("湿度"+weather_list_main[4]);//湿度
    });

    connect(this, &Widget::destroy, this, [=]()//析构
    {
        get_weather->quit();
        get_weather->wait();
        get_weather->deleteLater();  // delete t1;
    });


}
void Widget::weather_update(void){
    //天气信息获取调用python
//    get_weather=new spider;
//    get_weather->work();
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), SLOT(GetInfo()));
    timer->start(15000); //15s执行一次,定时器
    //GetInfo();

    //get_weather->start();
}

void Widget::GetInfo()
{
    char quest_array[256]="https://www.mxnzp.com/api/weather/current/如皋?app_id=donbyjnojulcspv7&app_secret=ZTkxdVk3alhSbkdqb1REaWFVcnAvdz09";
    QNetworkRequest quest;
    //sprintf(quest_array,"%s%s",quest_array,ui->lineEdit->text().toUtf8().data());
    //sprintf(quest_array,"%s%s",quest_array,local_city.toUtf8().data());
    quest.setUrl(QUrl(quest_array));
    quest.setHeader(QNetworkRequest::UserAgentHeader,"RT-Thread ART");
    //connect(manager,SIGNAL(finished(QNetworkReply *)),this,SLOT(replyFinished(QNetworkReply*)));
    /*发送get网络请求*/
    manager->get(quest);
}
