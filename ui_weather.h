/********************************************************************************
** Form generated from reading UI file 'weather.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEATHER_H
#define UI_WEATHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Weather
{
public:
    QWidget *widget;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label_temp;
    QLabel *label;
    QLabel *label_weather;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_wind;
    QLabel *label_2;
    QLabel *label_temp_2;
    QLabel *label_3;
    QLabel *label_pressure;
    QLabel *label_4;

    void setupUi(QWidget *Weather)
    {
        if (Weather->objectName().isEmpty())
            Weather->setObjectName(QStringLiteral("Weather"));
        Weather->resize(767, 418);
        widget = new QWidget(Weather);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 40, 711, 331));
        widget1 = new QWidget(widget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(0, 0, 711, 191));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_temp = new QLabel(widget1);
        label_temp->setObjectName(QStringLiteral("label_temp"));
        label_temp->setStyleSheet(QString::fromUtf8("font: 75 60pt \"\351\273\221\344\275\223\";"));

        horizontalLayout->addWidget(label_temp);

        label = new QLabel(widget1);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QString::fromUtf8("font: 75 20pt \"\351\273\221\344\275\223\";"));

        horizontalLayout->addWidget(label);

        label_weather = new QLabel(widget1);
        label_weather->setObjectName(QStringLiteral("label_weather"));

        horizontalLayout->addWidget(label_weather);

        widget2 = new QWidget(widget);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(0, 190, 711, 141));
        horizontalLayout_2 = new QHBoxLayout(widget2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_wind = new QLabel(widget2);
        label_wind->setObjectName(QStringLiteral("label_wind"));

        horizontalLayout_2->addWidget(label_wind);

        label_2 = new QLabel(widget2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 75 18pt \"\351\273\221\344\275\223\";"));

        horizontalLayout_2->addWidget(label_2);

        label_temp_2 = new QLabel(widget2);
        label_temp_2->setObjectName(QStringLiteral("label_temp_2"));

        horizontalLayout_2->addWidget(label_temp_2);

        label_3 = new QLabel(widget2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 75 18pt \"\351\273\221\344\275\223\";"));

        horizontalLayout_2->addWidget(label_3);

        label_pressure = new QLabel(widget2);
        label_pressure->setObjectName(QStringLiteral("label_pressure"));

        horizontalLayout_2->addWidget(label_pressure);

        label_4 = new QLabel(widget2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 75 18pt \"\351\273\221\344\275\223\";"));

        horizontalLayout_2->addWidget(label_4);


        retranslateUi(Weather);

        QMetaObject::connectSlotsByName(Weather);
    } // setupUi

    void retranslateUi(QWidget *Weather)
    {
        Weather->setWindowTitle(QApplication::translate("Weather", "Form", 0));
        label_temp->setText(QApplication::translate("Weather", "22\302\260", 0));
        label->setText(QApplication::translate("Weather", "\345\244\232\344\272\221", 0));
        label_weather->setText(QApplication::translate("Weather", "TextLabel", 0));
        label_wind->setText(QApplication::translate("Weather", "TextLabel", 0));
        label_2->setText(QApplication::translate("Weather", "\350\245\277\345\214\227\351\243\216 2\347\272\247", 0));
        label_temp_2->setText(QApplication::translate("Weather", "TextLabel", 0));
        label_3->setText(QApplication::translate("Weather", "\346\270\251\345\272\24630%", 0));
        label_pressure->setText(QApplication::translate("Weather", "TextLabel", 0));
        label_4->setText(QApplication::translate("Weather", "\346\260\224\345\216\2131016hpa", 0));
    } // retranslateUi

};

namespace Ui {
    class Weather: public Ui_Weather {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHER_H
