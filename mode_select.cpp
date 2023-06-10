#include"widget.h"
#include "ui_widget.h"
#include <QWidget>

#include <QFile>
#include <QMessageBox>
#include<QString>
#include<QPixmap>
#include<qdebug.h>




void Widget::on_tbnSelect_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->mode);
}
