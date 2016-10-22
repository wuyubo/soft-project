#ifndef ADTCP_H
#define ADTCP_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>

#include <QList>
#include <QListWidget>
#include "client.h"
#include <QThread>
#include <QMutex>


enum MsgType{WEATHER, MASSEGE, VIDEO};


class AdTcp : public QTcpServer
{
    Q_OBJECT
public:
     AdTcp(QListWidget *_client_lw, QObject *parent = 0);
     ~AdTcp();
    static QString current_msg;
signals:

public slots:
    void newClient();
    void read_id();
    void rmClient();

    void broadcastMsg(QString msg);
private:
    QList<Client> *client_list;
    QListWidget *client_lw;


    //QMutex *write_mutex;
};

#endif // ADTCP_H
