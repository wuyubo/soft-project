#ifndef WEATHER_H
#define WEATHER_H

#include <QObject>
#include <QLabel>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtWidgets/QComboBox>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonParseError>
#include <QJsonObject>

#include <QTimer>

#define WEATHER 0

class Weather : public QObject
{
    Q_OBJECT
public:
    explicit Weather( QLabel *_label, QComboBox *_city_cb, QComboBox *_area_cb,QObject *parent = 0);
    ~Weather();
    static QString current_wd;

signals:
    void broadcast(QString _msg);

public slots:
    void showWeather(QString weather);
    void findArea(QString _city);
    void getWeather(QString _city);
    void readyWeather();
    void updateWd();
private:
    QLabel *label;
    QSqlQuery *query;
    QComboBox *city_cb;
    QComboBox *area_cb;
    QString city;

    QNetworkAccessManager *net_manager;
    QNetworkRequest       *net_request;
    QNetworkReply         *net_reply;

    QTimer *timer;
};

#endif // WEATHER_H
