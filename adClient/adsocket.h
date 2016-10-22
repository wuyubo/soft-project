#ifndef ADSOCKET_H
#define ADSOCKET_H

#include <QTcpSocket>
#include <QHostAddress>
#include <QTimer>
#include <QThread>


enum MsgType{WEATHER, MASSEGE, VIDEO};

class AdSocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit AdSocket(QObject *parent = 0);
    ~AdSocket();
    void analysis_cmd(QString cmd);
signals:
    void showWeather(QString wt);
    void setMsg(QString txt);
    void playVideo(QString _vdo);

public slots:
    void readMsg();
    void conSuc();
    void conAgain();
    void discon();


private:
    QString id;
    QString msg;
    QTimer *timer;
};

#endif // ADSOCKET_H
