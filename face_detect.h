#ifndef FACE_DETECT_H
#define FACE_DETECT_H
#include<iostream>
#include<QThread>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QHttpMultiPart>
#include <QFile>
#include <QUrlQuery>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QBuffer>
#include <QFileDialog>
#include <QMessageBox>
#include <QObject>

using namespace std;


class Face_Detect:public QThread
{
    Q_OBJECT
public:
    QNetworkAccessManager *manager;
    //应答数据
    QByteArray replyData;
    //请求地址
    QString requestUrl;
    //Access Token
    QString accessToken;
    //图片路径
    QString imgPath;

public:
    Face_Detect();
protected:
    void run();

private slots:
    void replyFinished(QNetworkReply *reply);
//    void on_btnStartIdentify_clicked();
//    void on_openImgBtn_clicked();
//    void on_pushButton_clicked();
};

#endif // FACE_DETECT_H
