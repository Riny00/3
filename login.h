#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "widget.h"
#include <QCamera>
#include <QTimer>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
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

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();
    //加载qss文件
    bool LoadStyleSheet(const QString &StyleSheetFile);
    QString FaceImg;
    QString image2base64_str(const QImage& img);


public slots:
    static void FaceRegisterReply(QNetworkReply* reply);//人脸注册槽

private slots:
    void timeoutslots();//进度条槽函数
    void on_main_btn_clicked();
    void on_face_btn_clicked();
    void displayImage(int , QImage image);
    void on_enter_btn_clicked();//进入用户界面
    void on_paizhao_btn_clicked();
    void on_open_btn_clicked();

    void replyFinished(QNetworkReply *reply);
    void on_open_pic_btn_clicked();
    void on_register_btn_clicked();


private:
    Ui::Login *ui;

    QString groupid="";//用户组号
    QString user_id="";//用户名称

    QTimer *timer;//进度条定时器
    Widget*user;//用户界面
    QCamera *camera; //系统摄像头
    QCameraViewfinder *viewfinder; //展示窗口
    QCameraImageCapture *CamerimageCapture;//对记录的媒体资源进行捕捉
 ////////////////////////////
    QNetworkAccessManager *manager;
    QNetworkRequest NetRequest;
    //应答数据
    QByteArray replyData;
    //请求地址
    QString requestUrl;
    QString FaceAdd = "https://aip.baidubce.com/rest/2.0/face/v3/faceset/user/add";
    //Access Token
    QString accessToken;
    //图片路径
    QString imgPath;
public slots:
    void FaceRegister(QImage image, QString group_id,QString user_id);
signals:
    void RegisterReply(QString content);
Q_SIGNALS:
    void timeout(QPrivateSignal);
};

#endif // LOGIN_H
