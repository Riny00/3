#include "spider.h"
#include <Python.h>
#include<QDebug>
#include<QFile>

spider::spider(QObject *parent) : QThread(parent)
{
    manager = new QNetworkAccessManager(this);  //新建QNetworkAccessManager对象

    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinished(QNetworkReply*)));//关联信号和槽

}

void spider::GetInfo()
{
    char quest_array[256]="https://www.mxnzp.com/api/weather/current/如皋?app_id=donbyjnojulcspv7&app_secret=ZTkxdVk3alhSbkdqb1REaWFVcnAvdz09";
    QNetworkRequest quest;
    //sprintf(quest_array,"%s%s",quest_array,ui->lineEdit->text().toUtf8().data());
    //sprintf(quest_array,"%s%s",quest_array,local_city.toUtf8().data());
    quest.setUrl(QUrl(quest_array));
    quest.setHeader(QNetworkRequest::UserAgentHeader,"RT-Thread ART");
    //connect(manager,SIGNAL(finished(QNetworkReply *)),this,SLOT(replyFinished(QNetworkReply*)));
    /*发送get网络请求*/
    manager->get(quest);
}

void spider::work()
{
    GetInfo();

}


void spider::run()
{
    qDebug()<<"子线程启动"<<endl;

    //GetInfo();




}

void spider::replyFinished(QNetworkReply *reply)
{
    qDebug()<<"finish!!";

    //QTextCodec *codec = QTextCodec::codecForName("utf8");
    QString all = reply->readAll();//codec->toUnicode().toLocal8Bit();
    QJsonParseError err;
    QJsonDocument json_recv = QJsonDocument::fromJson(all.toUtf8(),&err);

    qDebug() << err.error;

    if(!json_recv.isNull())
    {
        QJsonObject object = json_recv.object();
        qDebug()<<object<<endl;
        QJsonObject dataValue = object.value(QStringLiteral("data")).toObject();

        QString loc = dataValue["address"].toString();                   //位置
        QString weather=dataValue["weather"].toString();                 //天气
        QString temp = dataValue["temp"].toString();                     //温度
        QString humidity=dataValue["humidity"].toString();               //湿度
        QString windDirection=dataValue["windDirection"].toString();     //风向
        QString windPower=dataValue["windPower"].toString();             //风力
        weather_list.append(loc);
        weather_list.append(weather);
        weather_list.append(temp);
        weather_list.append(humidity);
        weather_list.append(windDirection);
        weather_list.append(windPower);

    }
    else
    {
        qDebug()<<"json_recv is NULL or is not a object !!";
    }
    reply->deleteLater();
}








//子线程调用python
//void spider::run()
//{
//    Py_SetPythonHome((const wchar_t *)(L"D:/Programmingtools/Python"));
//    //进行初始化
//    Py_Initialize();

//    //如果初始化失败，返回
//    if(!Py_IsInitialized())
//    {
//        qDebug()<<"Py_IsInitialized is null";
//        return;
//    }

//    PyRun_SimpleString("import sys");
//    PyRun_SimpleString("sys.argv = ['python.py']");
//    PyRun_SimpleString("sys.path.append('./')");

//    //加载模块，模块名称为scirptThree，就是scirptThree.py文件
//    PyObject *pModule = PyImport_ImportModule("weather");

//    //如果加载失败，则返回
//    if(!pModule)
//    {
//        qDebug()<<"pModule is null ";

//    }
//    else
//    {
//        //通过PyObject_CallMethod方法向加载的pModule模块对象的receiveArg方法注入参数。iis表示int int String;1,2,"ahut"即为传入的参数
//        PyObject* pRet=PyObject_CallMethod(pModule,"main","i",5);
//        if (!pRet)
//        {
//            printf("不能找到 pRet");

//        }
//        if(PyLong_Check(pRet))
//        {
//            //字符串
//            const char* s=PyUnicode_AsUTF8(pRet);
//            QString strout=QLatin1String(s);
//            QString result=PyString_AsString(pRet);
//            qDebug()<<result;   //打印输出

//            //数字
//            //int iout =PyLong_AsLong(pRet);
//            //qDebug()<<iout<<endl;  //打印输出
//        }
//        else
//            qDebug()<<"return 1type is not Long!";
//    }
//    Py_Finalize();//释放对象

//    QVector<QString> weather_list;
//    QFile file("./weather.txt");
//    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
//    {
//        qDebug()<<"Can't open the file!"<<endl;
//    }
//    while(!file.atEnd())
//    {
//        QByteArray line = file.readLine();
//        QString str = QString::fromLocal8Bit(line.data());//正常显示中文
//        str=str.remove(QRegExp("\\s"));//去掉空格、换行符
//        weather_list.append(str);
//        //qDebug()<< str;
//    }
//    emit sendtomain(weather_list);
//    //qDebug()<<"发送了啊"<<endl;
//}
