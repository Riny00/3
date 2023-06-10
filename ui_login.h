/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *widget_top_login;
    QLabel *label;
    QPushButton *face_btn;
    QPushButton *tool_btn;
    QPushButton *main_btn;
    QStackedWidget *stackedWidget_login;
    QWidget *page_3;
    QPushButton *enter_btn;
    QLabel *camera_label;
    QPushButton *open_btn;
    QPushButton *paizhao_btn;
    QLabel *camera_label_2;
    QProgressBar *progressBar;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QLabel *group_label_2;
    QWidget *layoutWidget1;
    QHBoxLayout *h_layout2;
    QLabel *label_5;
    QLabel *group_label;
    QWidget *page_4;
    QLabel *camera_label_3;
    QProgressBar *progressBar_2;
    QPushButton *open_pic_btn;
    QPushButton *register_btn;
    QLabel *label_6;
    QLineEdit *register_name;
    QLineEdit *register_group;
    QLabel *label_10;
    QLabel *label_8;
    QWidget *widget_button_login;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(859, 599);
        Login->setStyleSheet(QString::fromUtf8(""));
        widget_top_login = new QWidget(Login);
        widget_top_login->setObjectName(QString::fromUtf8("widget_top_login"));
        widget_top_login->setGeometry(QRect(0, 0, 861, 41));
        label = new QLabel(widget_top_login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 171, 31));
        label->setStyleSheet(QString::fromUtf8("color: rgb(142, 227, 235);\n"
"font: 9.5pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        face_btn = new QPushButton(widget_top_login);
        face_btn->setObjectName(QString::fromUtf8("face_btn"));
        face_btn->setGeometry(QRect(521, 11, 93, 28));
        face_btn->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"	color:white;\n"
"	font:bold;\n"
"	min-width:14ex;\n"
"	min-height:4ex;\n"
"	max-width:36ex;\n"
"	max-height:12ex;"));
        tool_btn = new QPushButton(widget_top_login);
        tool_btn->setObjectName(QString::fromUtf8("tool_btn"));
        tool_btn->setGeometry(QRect(636, 11, 93, 28));
        tool_btn->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"	color:white;\n"
"	font:bold;\n"
"	min-width:14ex;\n"
"	min-height:4ex;\n"
"	max-width:36ex;\n"
"	max-height:12ex;"));
        main_btn = new QPushButton(widget_top_login);
        main_btn->setObjectName(QString::fromUtf8("main_btn"));
        main_btn->setGeometry(QRect(752, 11, 93, 28));
        main_btn->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"	color:white;\n"
"	font:bold;\n"
"	min-width:14ex;\n"
"	min-height:4ex;\n"
"	max-width:36ex;\n"
"	max-height:12ex;"));
        stackedWidget_login = new QStackedWidget(Login);
        stackedWidget_login->setObjectName(QString::fromUtf8("stackedWidget_login"));
        stackedWidget_login->setGeometry(QRect(0, 60, 861, 521));
        stackedWidget_login->setStyleSheet(QString::fromUtf8(""));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        enter_btn = new QPushButton(page_3);
        enter_btn->setObjectName(QString::fromUtf8("enter_btn"));
        enter_btn->setGeometry(QRect(810, 240, 58, 50));
        enter_btn->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"	color:white;\n"
"	font:bold;\n"
"	min-width:14ex;\n"
"	min-height:4ex;\n"
"	max-width:36ex;\n"
"	max-height:12ex;"));
        camera_label = new QLabel(page_3);
        camera_label->setObjectName(QString::fromUtf8("camera_label"));
        camera_label->setGeometry(QRect(50, 0, 361, 421));
        camera_label->setStyleSheet(QString::fromUtf8("border:0.5px solid #242424;\n"
"font: italic 25pt \"Arial\";\n"
"color: rgb(255, 255, 255);"));
        open_btn = new QPushButton(page_3);
        open_btn->setObjectName(QString::fromUtf8("open_btn"));
        open_btn->setGeometry(QRect(100, 440, 111, 31));
        open_btn->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"	color:white;\n"
"	font:bold;\n"
"	min-width:14ex;\n"
"	min-height:4ex;\n"
"	max-width:36ex;\n"
"	max-height:12ex;"));
        paizhao_btn = new QPushButton(page_3);
        paizhao_btn->setObjectName(QString::fromUtf8("paizhao_btn"));
        paizhao_btn->setGeometry(QRect(270, 440, 111, 31));
        paizhao_btn->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"	color:white;\n"
"	font:bold;\n"
"	min-width:14ex;\n"
"	min-height:4ex;\n"
"	max-width:36ex;\n"
"	max-height:12ex;"));
        camera_label_2 = new QLabel(page_3);
        camera_label_2->setObjectName(QString::fromUtf8("camera_label_2"));
        camera_label_2->setGeometry(QRect(470, 0, 311, 341));
        camera_label_2->setStyleSheet(QString::fromUtf8("border:1px solid #242424;\n"
"font: italic 20pt \"Arial\";\n"
"color: rgb(255, 255, 255);"));
        progressBar = new QProgressBar(page_3);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(470, 460, 351, 23));
        progressBar->setValue(0);
        layoutWidget = new QWidget(page_3);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(470, 350, 311, 41));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("\n"
"font: italic 15pt \"Arial\";\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(label_7);

        group_label_2 = new QLabel(layoutWidget);
        group_label_2->setObjectName(QString::fromUtf8("group_label_2"));
        group_label_2->setStyleSheet(QString::fromUtf8("\n"
"font: italic 15pt \"Arial\";\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(group_label_2);

        layoutWidget1 = new QWidget(page_3);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(470, 400, 311, 41));
        h_layout2 = new QHBoxLayout(layoutWidget1);
        h_layout2->setObjectName(QString::fromUtf8("h_layout2"));
        h_layout2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("\n"
"font: italic 15pt \"Arial\";\n"
"color: rgb(255, 255, 255);"));

        h_layout2->addWidget(label_5);

        group_label = new QLabel(layoutWidget1);
        group_label->setObjectName(QString::fromUtf8("group_label"));
        group_label->setStyleSheet(QString::fromUtf8("\n"
"font: italic 15pt \"Arial\";\n"
"color: rgb(255, 255, 255);"));

        h_layout2->addWidget(group_label);

        stackedWidget_login->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        camera_label_3 = new QLabel(page_4);
        camera_label_3->setObjectName(QString::fromUtf8("camera_label_3"));
        camera_label_3->setGeometry(QRect(50, 40, 361, 401));
        camera_label_3->setStyleSheet(QString::fromUtf8("border:0.5px solid #242424;\n"
"font: italic 25pt \"Arial\";\n"
"color: rgb(255, 255, 255);"));
        progressBar_2 = new QProgressBar(page_4);
        progressBar_2->setObjectName(QString::fromUtf8("progressBar_2"));
        progressBar_2->setGeometry(QRect(470, 420, 351, 23));
        progressBar_2->setValue(0);
        open_pic_btn = new QPushButton(page_4);
        open_pic_btn->setObjectName(QString::fromUtf8("open_pic_btn"));
        open_pic_btn->setGeometry(QRect(470, 300, 111, 31));
        open_pic_btn->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"	color:white;\n"
"	font:bold;\n"
"	min-width:14ex;\n"
"	min-height:4ex;\n"
"	max-width:36ex;\n"
"	max-height:12ex;"));
        register_btn = new QPushButton(page_4);
        register_btn->setObjectName(QString::fromUtf8("register_btn"));
        register_btn->setGeometry(QRect(690, 300, 111, 31));
        register_btn->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"	color:white;\n"
"	font:bold;\n"
"	min-width:14ex;\n"
"	min-height:4ex;\n"
"	max-width:36ex;\n"
"	max-height:12ex;"));
        label_6 = new QLabel(page_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(460, 40, 341, 201));
        label_6->setStyleSheet(QString::fromUtf8("border:0.5px solid #242424;\n"
"font: italic 25pt \"Arial\";\n"
"color: rgb(255, 255, 255);"));
        register_name = new QLineEdit(page_4);
        register_name->setObjectName(QString::fromUtf8("register_name"));
        register_name->setGeometry(QRect(600, 80, 191, 41));
        register_name->setStyleSheet(QString::fromUtf8("font: italic 16pt \"Arial\";\n"
"color: rgb(85, 255, 0);"));
        register_group = new QLineEdit(page_4);
        register_group->setObjectName(QString::fromUtf8("register_group"));
        register_group->setGeometry(QRect(597, 161, 191, 41));
        register_group->setStyleSheet(QString::fromUtf8("font: italic 16pt \"Arial\";\n"
"color: rgb(85, 255, 0);"));
        label_10 = new QLabel(page_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(469, 152, 131, 51));
        label_10->setStyleSheet(QString::fromUtf8("\n"
"font: italic 16pt \"Arial\";\n"
"color: rgb(255, 255, 255);"));
        label_8 = new QLabel(page_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(470, 70, 131, 51));
        label_8->setStyleSheet(QString::fromUtf8("\n"
"font: italic 16pt \"Arial\";\n"
"color: rgb(255, 255, 255);"));
        stackedWidget_login->addWidget(page_4);
        widget_button_login = new QWidget(Login);
        widget_button_login->setObjectName(QString::fromUtf8("widget_button_login"));
        widget_button_login->setGeometry(QRect(0, 570, 861, 31));
        label_2 = new QLabel(widget_button_login);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(480, 20, 171, 31));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 9.5pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_3 = new QLabel(widget_button_login);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(370, 0, 171, 31));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 9.5pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        retranslateUi(Login);

        stackedWidget_login->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Form", nullptr));
        label->setText(QApplication::translate("Login", "\346\231\272\350\203\275\345\256\266\345\261\205\345\260\217\345\212\251\346\211\213", nullptr));
        face_btn->setText(QApplication::translate("Login", "\344\272\272\350\204\270\345\275\225\345\205\245", nullptr));
        tool_btn->setText(QApplication::translate("Login", "\345\267\245\345\205\267\347\256\261", nullptr));
        main_btn->setText(QApplication::translate("Login", "\344\270\273\351\241\265", nullptr));
        enter_btn->setText(QString());
        camera_label->setText(QApplication::translate("Login", "          video", nullptr));
        open_btn->setText(QApplication::translate("Login", "\346\211\223\345\274\200\346\221\204\345\203\217\345\244\264", nullptr));
        paizhao_btn->setText(QApplication::translate("Login", "\344\272\272\350\204\270\350\257\206\345\210\253", nullptr));
        camera_label_2->setText(QApplication::translate("Login", "         image", nullptr));
        label_7->setText(QApplication::translate("Login", "\345\247\223\345\220\215:", nullptr));
        group_label_2->setText(QApplication::translate("Login", "TextLabel", nullptr));
        label_5->setText(QApplication::translate("Login", "\347\273\204\345\217\267:", nullptr));
        group_label->setText(QApplication::translate("Login", "TextLabel", nullptr));
        camera_label_3->setText(QApplication::translate("Login", "          video", nullptr));
        open_pic_btn->setText(QApplication::translate("Login", "\346\211\223\345\274\200\345\233\276\347\211\207", nullptr));
        register_btn->setText(QApplication::translate("Login", "\344\272\272\350\204\270\346\263\250\345\206\214", nullptr));
        label_6->setText(QString());
        register_name->setText(QString());
        label_10->setText(QApplication::translate("Login", "group id:", nullptr));
        label_8->setText(QApplication::translate("Login", "name:", nullptr));
        label_2->setText(QApplication::translate("Login", "\346\231\272\350\203\275\345\256\266\345\261\205\345\260\217\345\212\251\346\211\213", nullptr));
        label_3->setText(QApplication::translate("Login", "\347\233\220\345\237\216\345\270\210\350\214\203\345\255\246\351\231\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
