#include"widget.h"
#include "ui_widget.h"
#include <QWidget>

#include <QFile>
#include <QMessageBox>
#include<QString>
#include<QPixmap>
#include<QTcpSocket>
#include<qdebug.h>
#include <QHostAddress>


void Widget::initsetting()
{
    m_tcp = new QTcpSocket(this);
    ui->status->setStyleSheet(tr("border-image: url(:/icon/disconnect.png);"));
    ui->btn_disconnect->setDisabled(true);//设置断开连接按钮禁用

    // 检测是否和服务器是否连接成功了
    connect(m_tcp, &QTcpSocket::connected, this, [=]()
    {
        ui->status->setStyleSheet(tr("border-image: url(:/icon/connect.png);"));
        ui->btn_connect->setDisabled(true);//设置连接按钮禁用
        ui->btn_disconnect->setDisabled(false);//设置断开连接按钮开启
    });

    //检测服务器是否回复了数据
    connect(m_tcp, &QTcpSocket::readyRead, [=]()
    {
        // 接收服务器发送的数据
        QByteArray recvMsg = m_tcp->readAll();
        QString res;
        res.prepend(recvMsg);

        QStringList list = res.split("|");

        tmp=list[0];
        QString hum=list[1];

        qDebug()<<"temp:"<<tmp<<endl;
        qDebug()<<"hum:"<<hum<<endl;
        ui->label_19->setText(tmp);
        ui->label_20->setText(hum);


        //ui->record->append( + );
    });

    // 检测服务器是否和客户端断开了连接
    connect(m_tcp, &QTcpSocket::disconnected, this, [=]()
    {
        ui->btn_connect->setDisabled(false);//设置连接按钮开启
        ui->btn_disconnect->setDisabled(true);//设置断开连接按钮禁用
        ui->status->setStyleSheet(tr("border-image: url(:/icon/disconnect.png);"));
    });


}

//设置界面跳转
void Widget::on_tbnSetting_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->setting);
}

//连接按钮
void Widget::on_btn_connect_clicked()
{
    unsigned short port = ui->port_line->text().toInt();
    QString ip=ui->ip_line->text();
    //m_tcp->connectToHost(QHostAddress(ip),port);
    m_tcp->connectToHost(QHostAddress(ip),port);
    qDebug()<<"on_btn_connect_clicked"<<endl;
}

//断开连接按钮
void Widget::on_btn_disconnect_clicked()
{

    m_tcp->close();
    qDebug()<<"on_btn_disconnect_clicked"<<endl;
}
