#include "adsocket.h"
#include <QDebug>

AdSocket::AdSocket(QObject *parent) :
    QTcpSocket(parent)
{
    id = "0011";
    msg = "";
    timer = new QTimer;
    connect(this, SIGNAL(readyRead()),this, SLOT(readMsg()));
    connect(this, SIGNAL(connected()),this, SLOT(conSuc()));
    connect(this, SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(conAgain()));
    connect(this, SIGNAL(disconnected()),this, SLOT(conAgain()));
    connect(timer, SIGNAL(timeout()), this, SLOT(conAgain()));
    connectToHost(QHostAddress("192.168.1.140"), 9999);
}

AdSocket::~AdSocket()
{

}

//接收信息
void AdSocket::readMsg()
{
    msg = readAll();

    QStringList msgs = msg.split("#");
    for(int i = 0; i<msgs.size(); i++)
    {
        analysis_cmd(msgs[i]);
    }
}

//解析命令
void AdSocket::analysis_cmd(QString cmd)
{
    QStringList msgs = cmd.split("|");

    msg.clear();
    if(msgs.size() >= 4)
    {
        if(msgs[0] == "^")
        {
            switch (msgs[1].toInt())
            {
            case WEATHER:
                emit showWeather(msgs[2]);
                break;
            case MASSEGE:
                emit setMsg(msgs[2]);
                break;
            case VIDEO:
                emit playVideo(msgs[2]);
                break;
            default:
                break;
            }
        }

    }
}

void AdSocket::conSuc()
{
    this->write(id.toUtf8());
    qDebug()<<"connect success";
}

void AdSocket::discon()
{
    timer->start(500);
}

void AdSocket::conAgain()
{
 //  if(this->state() == QAbstractSocket::UnconnectedState)
//    {
//        abort();
        QThread::usleep(1000);
        connectToHost(QHostAddress("192.168.1.140"), 9999);
        qDebug()<<"connect again";
 //   }
//   else
 //   {
//       timer->stop();
 //   }
}
