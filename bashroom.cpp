#include"widget.h"
#include "ui_widget.h"
#include <QWidget>

#include <QFile>
#include <QMessageBox>
#include<QString>
#include<QPixmap>
#include<qdebug.h>


void Widget::on_btn_bashroom_sub_clicked()//??
{
    int tmp=ui->label_bashroom_temp->text().toInt()-1;//QString?int
    ui->label_bashroom_temp->setText(QString::number(tmp));//int?QString

    //qDebug()<<tmp;
}

void Widget::on_btn_bashroom_add_clicked()//??
{
    int tmp=ui->label_bashroom_temp->text().toInt()+1;//QString?int
    ui->label_bashroom_temp->setText(QString::number(tmp));//int?QString

    //qDebug()<<tmp;
}
