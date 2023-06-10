#include"widget.h"
#include "ui_widget.h"
#include <QWidget>

#include <QFile>
#include <QMessageBox>
#include<QPixmap>
#include<qdebug.h>

//客厅界面初始化
void Widget::initparlor()
{
    QPixmap icon1(tr(":/icon/light_off.png"));
    ui->label_parlor_light->setPixmap(icon1);
    ui->label_parlor_light->setFixedSize(icon1.size());
    this->parlor_light_flag=true;
    ui->label_parlor_light->setScaledContents(true);


    QPixmap icon2(tr(":/icon/airoff.png"));
    ui->label_air->setPixmap(icon2);
    ui->label_air->setFixedSize(icon2.size());
    this->air_flag=true;
    ui->label_air->setScaledContents(true);

    QPixmap icon3(tr(":/icon/tv_off.png"));
    ui->label_tv->setPixmap(icon3);
    ui->label_tv->setFixedSize(icon3.size());
    this->tv_flag=true;
    ui->label_tv->setScaledContents(true);

    QPixmap icon4(tr(":/icon/curtain_close.png"));
    ui->label_curtain->setPixmap(icon4);
    ui->label_curtain->setFixedSize(icon4.size());
    this->curtain_flag=true;
    ui->label_curtain->setScaledContents(true);

    ui->btn_air->setStyleSheet(tr("border-image: url(:/icon/off.png);"));
    ui->btn_parlor_light->setStyleSheet(tr("border-image: url(:/icon/off.png);"));
    ui->btn_tv->setStyleSheet(tr("border-image: url(:/icon/off.png);"));
    ui->btn_curtain->setStyleSheet(tr("border-image: url(:/icon/off.png);"));

}

//空调开关
void Widget::on_btn_air_clicked()
{

    if(this->air_flag)
    {
        QPixmap icon1(tr(":/icon/kongton.png"));
        ui->label_air->setPixmap(icon1);
        ui->label_air->setFixedSize(icon1.size());
        ui->label_air->setScaledContents(true);
        this->air_flag=false;
        ui->btn_air->setStyleSheet(tr("border-image: url(:/icon/on.png);"));

        m_tcp->write("air_on");
   }
    else
    {
        QPixmap icon2(tr(":/icon/kongtoff.png"));
        ui->label_air->setPixmap(icon2);
        ui->label_air->setFixedSize(icon2.size());
        this->air_flag=true;
        ui->label_air->setScaledContents(true);
        ui->btn_air->setStyleSheet(tr("border-image: url(:/icon/off.png);"));
        m_tcp->write("air_off");
    }
}

//客厅灯开关
void Widget::on_btn_parlor_light_clicked()
{
    if(this->parlor_light_flag)
    {
        QPixmap icon1(tr(":/icon/light_on.png"));//灯
        this->parlor_light_flag=false;
        ui->label_parlor_light->setPixmap(icon1);
        ui->label_parlor_light->setFixedSize(icon1.size());
        ui->label_parlor_light->setScaledContents(true);
        ui->btn_parlor_light->setStyleSheet(tr("border-image: url(:/icon/on.png);"));//按钮
        m_tcp->write("light1_on");
   }
    else
    {
        QPixmap icon2(tr(":/icon/light_off.png"));
        this->parlor_light_flag=true;
        ui->label_parlor_light->setPixmap(icon2);
        ui->label_parlor_light->setFixedSize(icon2.size());
        ui->label_parlor_light->setScaledContents(true);

        ui->btn_parlor_light->setStyleSheet(tr("border-image: url(:/icon/off.png);"));
         m_tcp->write("light1_off");
    }

}

//电视开关
void Widget::on_btn_tv_clicked()
{
    if(this->parlor_light_flag)
    {
        QPixmap icon1(tr(":/icon/tv_on.png"));
        this->parlor_light_flag=false;
        ui->label_tv->setPixmap(icon1);
        ui->label_tv->setFixedSize(icon1.size());
        ui->label_tv->setScaledContents(true);
        ui->btn_tv->setStyleSheet(tr("border-image: url(:/icon/on.png);"));
        m_tcp->write("tv_on");
   }
    else
    {
        QPixmap icon2(tr(":/icon/tv_off.png"));
        this->parlor_light_flag=true;
        ui->label_tv->setPixmap(icon2);
        ui->label_tv->setFixedSize(icon2.size());
        ui->label_tv->setScaledContents(true);
        ui->btn_tv->setStyleSheet(tr("border-image: url(:/icon/off.png);"));

        m_tcp->write("tv_off");
    }
}

//窗帘开关
void Widget::on_btn_curtain_clicked()
{
    if(this->curtain_flag)
    {
        QPixmap icon1(tr(":/icon/curtain_open.png"));
        this->curtain_flag=false;
        ui->label_curtain->setPixmap(icon1);
        ui->label_curtain->setFixedSize(icon1.size());
        ui->label_curtain->setScaledContents(true);

        ui->btn_curtain->setStyleSheet(tr("border-image: url(:/icon/on.png);"));
        m_tcp->write("curtain_on");
   }
    else
    {
        QPixmap icon2(tr(":/icon/curtain_close.png"));
        this->curtain_flag=true;
        ui->label_curtain->setPixmap(icon2);
        ui->label_curtain->setFixedSize(icon2.size());
        ui->label_curtain->setScaledContents(true);

        ui->btn_curtain->setStyleSheet(tr("border-image: url(:/icon/off.png);"));
        m_tcp->write("curtain_off");
    }
}
