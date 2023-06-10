#include"widget.h"
#include "ui_widget.h"
#include <QWidget>

#include <QFile>
#include <QMessageBox>
#include<QString>
#include<QPixmap>
#include<qdebug.h>
#include<QValueAxis>
#include <QtCharts/QLineSeries>

void Widget::initchart()
{
    //定时器
    m_timer_Temp=new QTimer(this);
    m_timer_Temp->setSingleShot(false);
    QObject::connect(m_timer_Temp, SIGNAL(timeout()), this, SLOT(slotTimeout_Temp()));
//    //定时器
//    m_timer_Hum=new QTimer(this);
//    m_timer_Hum->setSingleShot(false);
//    //QObject::connect(m_timer_Hum, SIGNAL(timeout()), this, SLOT(slotTimeout()));
//    //定时器
//    m_timer_Temp=new QTimer(this);
//    m_timer_Temp->setSingleShot(false);
//    //QObject::connect(m_timer_Temp, SIGNAL(timeout()), this, SLOT(slotTimeout()));

    //温度
    m_axisX_Temp = new QValueAxis();
    m_axisY_Temp = new QValueAxis();
    m_axisX_Temp->setTitleText("X-label");
    m_axisY_Temp->setTitleText("Y-label");
    m_axisX_Temp->setMin(0);
    m_axisY_Temp->setMax(0);
    m_axisX_Temp->setMax(AXIS_MAX_X);
    m_axisY_Temp->setMax(AXIS_MAX_Y);

    m_lineSeries_Temp = new QLineSeries();                             // 创建曲线绘制对象
    m_lineSeries_Temp->setPointsVisible(true);                         // 设置数据点可见
    m_lineSeries_Temp->setName("温度变化");                            // 图例名称

    m_chart_Temp = new QChart();                                        // 创建图表对象
    m_chart_Temp->addAxis(m_axisX_Temp, Qt::AlignLeft);                      // 将X轴添加到图表上
    m_chart_Temp->addAxis(m_axisY_Temp, Qt::AlignBottom);                    // 将Y轴添加到图表上
    m_chart_Temp->addSeries(m_lineSeries_Temp);                              // 将曲线对象添加到图表上
    m_chart_Temp->setAnimationOptions(QChart::SeriesAnimations);        // 动画：能使曲线绘制显示的更平滑，过渡效果更好看

    m_lineSeries_Temp->attachAxis(m_axisX_Temp);                             // 曲线对象关联上X轴，此步骤必须在m_chart->addSeries之后
    m_lineSeries_Temp->attachAxis(m_axisY_Temp);                             // 曲线对象关联上Y轴，此步骤必须在m_chart->addSeries之后

    ui->widget_temp->setChart(m_chart_Temp);                           // 将图表对象设置到graphicsView上进行显示
    ui->widget_temp->setRenderHint(QPainter::Antialiasing);       // 设置渲染：抗锯齿，如果不设置那么曲线就显得不平滑

    //湿度
    m_axisX_Hum = new QValueAxis();
    m_axisY_Hum = new QValueAxis();
    m_axisX_Hum->setTitleText("X-label");
    m_axisY_Hum->setTitleText("Y-label");
    m_axisX_Hum->setMin(0);
    m_axisY_Hum->setMax(0);
    m_axisX_Hum->setMax(AXIS_MAX_X);
    m_axisY_Hum->setMax(AXIS_MAX_Y);

    m_lineSeries_Hum = new QLineSeries();                             // 创建曲线绘制对象
    m_lineSeries_Hum->setPointsVisible(true);                         // 设置数据点可见
    m_lineSeries_Hum->setName("随机数曲线");                            // 图例名称

    m_chart_Hum = new QChart();                                        // 创建图表对象
    m_chart_Hum->addAxis(m_axisX_Hum, Qt::AlignLeft);                      // 将X轴添加到图表上
    m_chart_Hum->addAxis(m_axisY_Hum, Qt::AlignBottom);                    // 将Y轴添加到图表上
    m_chart_Hum->addSeries(m_lineSeries_Hum);                              // 将曲线对象添加到图表上
    m_chart_Hum->setAnimationOptions(QChart::SeriesAnimations);        // 动画：能使曲线绘制显示的更平滑，过渡效果更好看

    m_lineSeries_Hum->attachAxis(m_axisX_Hum);                             // 曲线对象关联上X轴，此步骤必须在m_chart->addSeries之后
    m_lineSeries_Hum->attachAxis(m_axisY_Hum);                             // 曲线对象关联上Y轴，此步骤必须在m_chart->addSeries之后

    ui->widget_hum->setChart(m_chart_Hum);                           // 将图表对象设置到graphicsView上进行显示
    ui->widget_hum->setRenderHint(QPainter::Antialiasing);       // 设置渲染：抗锯齿，如果不设置那么曲线就显得不平滑


    //烟雾浓度
    m_axisX_Smoke = new QValueAxis();
    m_axisY_Smoke = new QValueAxis();
    m_axisX_Smoke->setTitleText("X-label");
    m_axisY_Smoke->setTitleText("Y-label");
    m_axisX_Smoke->setMin(0);
    m_axisY_Smoke->setMax(0);
    m_axisX_Smoke->setMax(AXIS_MAX_X);
    m_axisY_Smoke->setMax(AXIS_MAX_Y);

    m_lineSeries_Smoke = new QLineSeries();                             // 创建曲线绘制对象
    m_lineSeries_Smoke->setPointsVisible(true);                         // 设置数据点可见
    m_lineSeries_Smoke->setName("随机数曲线");                            // 图例名称

    m_chart_Smoke = new QChart();                                        // 创建图表对象
    m_chart_Smoke->addAxis(m_axisX_Smoke, Qt::AlignLeft);                      // 将X轴添加到图表上
    m_chart_Smoke->addAxis(m_axisY_Smoke, Qt::AlignBottom);                    // 将Y轴添加到图表上
    m_chart_Smoke->addSeries(m_lineSeries_Smoke);                              // 将曲线对象添加到图表上
    m_chart_Smoke->setAnimationOptions(QChart::SeriesAnimations);        // 动画：能使曲线绘制显示的更平滑，过渡效果更好看

    m_lineSeries_Smoke->attachAxis(m_axisX_Smoke);                             // 曲线对象关联上X轴，此步骤必须在m_chart->addSeries之后
    m_lineSeries_Smoke->attachAxis(m_axisY_Smoke);                             // 曲线对象关联上Y轴，此步骤必须在m_chart->addSeries之后

    ui->widget_smoke->setChart(m_chart_Smoke);                           // 将图表对象设置到graphicsView上进行显示
    ui->widget_smoke->setRenderHint(QPainter::Antialiasing);       // 设置渲染：抗锯齿，如果不设置那么曲线就显得不平滑


    pointCount = 0;
    m_timer_Temp->start(1000);
}

void Widget::slotTimeout_Temp()
{
    if(pointCount > AXIS_MAX_X)
    {
        m_lineSeries_Temp->remove(0);
        m_chart_Temp->axisX()->setMin(pointCount - AXIS_MAX_X);
        m_chart_Temp->axisX()->setMax(pointCount);                    // 更新X轴范围
    }
    bool ok = false;
    int num1 = tmp.toInt(&ok, 10);
    //m_lineSeries_Temp->append(QPointF(pointCount, rand() % AXIS_MAX_Y));  // 更新显示（随机生成10以内的一个数）
    m_lineSeries_Temp->append(QPointF(pointCount, num1));  // 更新显示（随机生成10以内的一个数）
    pointCount++;
}


void Widget::on_tbnStatistic_clicked()//温度的温度界面跳转
{
    ui->stackedWidget->setCurrentWidget(ui->static_1);
}
void Widget::on_pushButton_4_clicked()//温度的湿度界面跳转
{
    ui->stackedWidget->setCurrentWidget(ui->static_2);
}
void Widget::on_pushButton_5_clicked()//温度的烟雾界面跳转
{
    ui->stackedWidget->setCurrentWidget(ui->static_3);
}
void Widget::on_pushButton_6_clicked()//湿度的温度界面跳转
{
    ui->stackedWidget->setCurrentWidget(ui->static_1);
}
void Widget::on_pushButton_8_clicked()//湿度的烟雾界面跳转
{
    ui->stackedWidget->setCurrentWidget(ui->static_3);
}
void Widget::on_pushButton_9_clicked()//烟雾的温度界面跳转
{
    ui->stackedWidget->setCurrentWidget(ui->static_1);
}
void Widget::on_pushButton_10_clicked()//烟雾的湿度界面跳转
{
    ui->stackedWidget->setCurrentWidget(ui->static_2);
}
