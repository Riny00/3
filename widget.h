#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtCharts>
#include<QTcpSocket>
#include <QTimer>
#include <QDateTime>
#include<QVector>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QString>
#include <QTextCodec>

#include "spider.h"

class QToolButton;//QToolButton声明
class QPushButton;
class QLabel;

QT_CHARTS_USE_NAMESPACE
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);

    ~Widget();

private slots:

    void on_tbnHome_clicked();//首页跳转函数

    void on_tbnControl_clicked();//家居控制跳转函数

    void on_tbnWeather_clicked();//天气界面跳转函数

    void on_tbnParlor_clicked();//客厅界面跳转函数

    void on_tbnBedRoom_clicked();//卧室界面跳转函数

    void on_tbnKitchen_clicked();//厨房界面跳转函数

    void on_tbnSafety_clicked();//浴室界面跳转函数

public slots:
    //时间更新
    void time_update(void);

    //天气数据更新
    void weather_update(void);

    //天气获取
    void GetInfo();

public:



    //时间设置
    void initDataTime();

    //界面初始化
    void initform();

    //天气界面初始化
    void initweather();

    //客厅界面初始化
    void initparlor();

    //厨房界面初始化
    void initkitchen();

    //卧室界面初始化
    void initbedroom();

    //加载qss文件
    bool LoadStyleSheet(const QString &StyleSheetFile);

    //设置ToolButton图标
    void setToolButtonStyle(QToolButton *tbn, const QString &text,int textSize,const QString iconName);


//家电控制标志
public:

    bool air_flag=true;//空调当前为关
    bool parlor_light_flag=true;//当前客厅灯关
    bool curtain_flag=true;//窗帘关
    bool tv_flag=true;//电视开关

    bool kitchen_light_flag=true;//厨房灯关
    bool Lampblack_flag=true;//油烟机

    bool bed_light_flag=true;//卧室灯关
    bool bed_air_flag=true;//卧室空调关


private slots:
    void reply(QNetworkReply *reply);//天气网络请求

    //设置界面
    void initsetting();//初始化

    //客厅
    void on_btn_air_clicked();//空调控制函数
    void on_btn_parlor_light_clicked();//客厅灯
    void on_btn_tv_clicked();//电视开关
    void on_btn_curtain_clicked();//窗帘开关



    //浴室
    void on_btn_bashroom_sub_clicked();//浴室温度减

    void on_btn_bashroom_add_clicked();//浴室温度加

    //厨房
    void on_btn_kitchen_light_clicked();//厨房灯

    void on_btn_Lampblack_clicked();//油烟机

    void on_btn_bed_light_clicked();

    void on_btn_bed_air_clicked();

    //模式选择界面


    void on_tbnSetting_clicked();
    void on_tbnStatistic_clicked();//数据统计界面跳转函数

    void initchart();//图表初始化
    void slotTimeout_Temp();
//    void slotTimeout_Hum();
//    void slotTimeout_Smoke();


    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();



    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_tbnSelect_clicked();//模式选择按钮

    void on_btn_connect_clicked();

    void on_btn_disconnect_clicked();

private:
    Ui::Widget *ui;
    QString tmp;//温度

    QNetworkAccessManager *manager;
    QNetworkRequest *quest;

    QTimer *m_timer_Temp;
    QTimer *m_timer_Hum;
    QTimer *m_timer_Smoke;
                    /*图表*/

                    /*温度图*/
    QChart* m_chart_Temp;/* 图表对象 */
    QValueAxis *m_axisX_Temp, *m_axisY_Temp;/* 横纵坐标轴对象 */
    QLineSeries* m_lineSeries_Temp;/* 曲线图对象 */
    const int AXIS_MAX_X = 70, AXIS_MAX_Y = 30;/* 横纵坐标最大显示范围 */
    int pointCount = 0;/* 用来记录数据点数 */

                    /*湿度图*/
    QChart* m_chart_Hum;/* 图表对象 */
    QValueAxis *m_axisX_Hum, *m_axisY_Hum;/* 横纵坐标轴对象 */
    QLineSeries* m_lineSeries_Hum;/* 曲线图对象 */


                    /*烟雾图*/
    QChart* m_chart_Smoke;/* 图表对象 */
    QValueAxis *m_axisX_Smoke, *m_axisY_Smoke;/* 横纵坐标轴对象 */
    QLineSeries* m_lineSeries_Smoke;/* 曲线图对象 */


    //tcp套接字
    QTcpSocket* m_tcp;
    //爬取的天气信息
    QVector<QString> weather_list_main;
    //更新天气信息子线程
    spider *get_weather;

Q_SIGNALS:
    void timeout(QPrivateSignal);

};

#endif // WIDGET_H
