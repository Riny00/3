#include"widget.h"
#include "ui_widget.h"
#include <QWidget>

#include <QFile>
#include <QMessageBox>
#include<QString>
#include<QPixmap>
#include<qdebug.h>


void Widget::initbedroom()
{
    ui->bed_light->setStyleSheet(tr("border-image: url(:/icon/light_off.png);"));
    QPixmap icon2(tr(":/icon/airoff.png"));
    ui->bed_air->setPixmap(icon2);
    ui->bed_air->setFixedSize(icon2.size());
    this->air_flag=true;
    ui->bed_air->setScaledContents(true);

}

void Widget::on_btn_bed_light_clicked()
{
    if(this->bed_light_flag)
    {
        ui->bed_light->setStyleSheet(tr("border-image: url(:/icon/light_on.png);"));
        this->bed_light_flag=false;
        ui->btn_bed_light->setStyleSheet(tr("border-image: url(:/icon/on.png);"));
        m_tcp->write("light2_on");
        //m_tcp->write("8");

   }
    else
    {
        ui->bed_light->setStyleSheet(tr("border-image: url(:/icon/light_off.png);"));
        this->bed_light_flag=true;
        ui->btn_bed_light->setStyleSheet(tr("border-image: url(:/icon/off.png);"));
        m_tcp->write("light2_off");
    }
}

void Widget::on_btn_bed_air_clicked()
{
    if(this->bed_air_flag)
    {
        ui->bed_air->setStyleSheet(tr("border-image: url(:/icon/airon.png);"));
        this->bed_air_flag=false;
        ui->btn_bed_air->setStyleSheet(tr("border-image: url(:/icon/on.png);"));
        m_tcp->write("air2_on");
   }
    else
    {
        ui->bed_air->setStyleSheet(tr("border-image: url(:/icon/airoff.png);"));
        this->bed_air_flag=true;
        ui->btn_bed_air->setStyleSheet(tr("border-image: url(:/icon/off.png);"));
        m_tcp->write("air2_off");
    }
}
