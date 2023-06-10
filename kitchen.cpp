#include"widget.h"
#include "ui_widget.h"
#include <QWidget>

#include <QFile>
#include <QMessageBox>
#include<QString>
#include<QPixmap>
#include<qdebug.h>

void Widget::initkitchen()
{
    ui->label_kitchen_light->setStyleSheet(tr("border-image: url(:/icon/light_off.png);"));
    ui->label_Lampblack->setStyleSheet(tr("border-image: url(:/icon/youyanoff.png);"));



    this->parlor_light_flag=true;
    this->Lampblack_flag=true;

}

void Widget::on_btn_kitchen_light_clicked()
{
    if(this->kitchen_light_flag)
    {
        ui->label_kitchen_light->setStyleSheet(tr("border-image: url(:/icon/light_on.png);"));
        this->kitchen_light_flag=false;
        ui->btn_kitchen_light->setStyleSheet(tr("border-image: url(:/icon/btncheckon.png);"));
        m_tcp->write("light3_on");
   }
    else
    {
        ui->label_kitchen_light->setStyleSheet(tr("border-image: url(:/icon/light_off.png);"));
        this->kitchen_light_flag=true;
        ui->btn_kitchen_light->setStyleSheet(tr("border-image: url(:/icon/btncheckoff.png);"));
        m_tcp->write("light3_off");
    }
}

void Widget::on_btn_Lampblack_clicked()
{
    if(this->Lampblack_flag)
    {
        ui->label_Lampblack->setStyleSheet(tr("border-image: url(:/icon/youyanon.png);"));
        this->Lampblack_flag=false;
        ui->btn_Lampblack->setStyleSheet(tr("border-image: url(:/icon/btncheckon.png);"));
        m_tcp->write("Lampblack_on");
   }
    else
    {
        ui->label_Lampblack->setStyleSheet(tr("border-image: url(:/icon/youyanoff.png);"));
        this->Lampblack_flag=true;
        ui->btn_Lampblack->setStyleSheet(tr("border-image: url(:/icon/btncheckoff.png);"));
        m_tcp->write("Lampblack_off");
    }
}
