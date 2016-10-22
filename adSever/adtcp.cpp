#include "adtcp.h"
#include "weather.h"
#include "advideo.h"
#include <QDebug>


QString AdTcp::current_msg="暂无广播信息";
AdTcp::AdTcp(QListWidget *_client_lw, QObject *parent) :
    QTcpServer(parent)
{
    if(!listen(QHostAddress::Any, 9999))
    {
        //QMessageBox::warning(this, "服务器启动失败");
        close();
    }

   // write_mutex = new QMutex;
    client_list = new QList<Client>;
    client_lw =_client_lw;

    connect(this, SIGNAL(newConnection()), this, SLOT(newClient()));
    qDebug()<<"init tcp";
  //  connect(this, SIGNAL(), this, SLOT(newClient()));
  //  connect(this, SIGNAL(acceptError(QAbstractSocket::SocketError)), this, SLOT(newClient()));
}

AdTcp::~AdTcp()
{
    delete client_list;
    close();
}

//新客户机连接
void AdTcp::newClient()
{
    Client *new_client = new Client;
    new_client->msocket = this->nextPendingConnection();

    connect(new_client->msocket, SIGNAL(readyRead()), this, SLOT(read_id()));\
    connect(new_client->msocket, SIGNAL(disconnected()), this, SLOT(rmClient()));
    client_list->append(*new_client);

    QString cmd=QString::number(WEATHER)+"|"+Weather::current_wd+"|$#^|"
                +QString::number(MASSEGE)+"|"+AdTcp::current_msg+"|$#^|"
                +QString::number(VIDEO)+"|"+AdVideo::current_vdo;

    broadcastMsg(cmd);
}

void AdTcp::read_id()
{
    QString id = client_list->last().msocket->readAll();
    if(id == "get")
        qDebug()<<"get";
    else
    {
         client_list->last().id = id;
         client_lw->addItem(id);
    }

}

//广播命令结客户机
void AdTcp::broadcastMsg(QString msg)
{
    msg = "^|"+msg+"|$#";
    int count = client_list->size();
    for(int i = 0; i< count; i++)
    {
        client_list->at(i).msocket->write(msg.toUtf8());
    }
}

void AdTcp::rmClient()
{
    qDebug()<<"someone disconnect";
    if(client_list->first().msocket->isSequential())
    {
        client_lw->clear();
    }
}
