#ifndef SPIDER_H
#define SPIDER_H

#include <QObject>
#include <QThread>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QString>
#include <QTextCodec>


class spider : public QThread
{
    Q_OBJECT

private:
    QNetworkAccessManager *manager;
    QNetworkRequest *quest;
    QVector<QString> weather_list;

public:
    explicit spider(QObject *parent = 0);
    void GetInfo();
    void work();

signals:
    void sendtomain(QVector<QString> weather_list);

protected:
    void run();

private slots:
    void replyFinished(QNetworkReply *reply);

public slots:
};

#endif // SPIDER_H
