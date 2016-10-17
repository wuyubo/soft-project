#ifndef ADPLAYER_H
#define ADPLAYER_H

#include <QMainWindow>
#include <QProcess>
#include <QTimer>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonValue>

namespace Ui {
class Adplayer;
}

class Adplayer : public QMainWindow
{
    Q_OBJECT

public:
    explicit Adplayer(QWidget *parent = 0);
    ~Adplayer();
public slots:
    void startPlay();
    void readPlayMsg();
    void readWeather();
    void requestWeather();

private:
    Ui::Adplayer *ui;
    QProcess *play_process;
    QTimer *mtimer;

    QNetworkAccessManager wmasager;
    QNetworkRequest wrequest;
    QNetworkReply   *wreply;
};

#endif // ADPLAYER_H
