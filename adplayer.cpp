#include "adplayer.h"
#include "ui_adplayer.h"


Adplayer::Adplayer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Adplayer)
{
    ui->setupUi(this);
    play_process = new QProcess;

    mtimer = new QTimer(this);
    connect(mtimer, SIGNAL(timeout()), this, SLOT(startPlay()));
    connect(play_process, SIGNAL(readyRead()), this, SLOT(readPlayMsg()));
    mtimer->start(100);
    ui->time_lb->setText("<<<<<<<<");

    wrequest.setUrl(QUrl("http://www.weather.com.cn/adat/sk/101280101.html"));
    connect(&wmasager, SIGNAL(finished(QNetworkReply*)),this, SLOT(readWeather()));

}

Adplayer::~Adplayer()
{
    delete play_process;
    delete ui;
}

void Adplayer::startPlay()
{
    mtimer->stop();
    disconnect(mtimer, SIGNAL(timeout()), this, SLOT(startPlay()));
   //delete mtimer;
    connect(mtimer, SIGNAL(timeout()), this, SLOT(requestWeather()));
    mtimer->start(2000);



/*//#ifdef ARM
    qDebug()<<"ARM";
    QString cmd("mplayer -slave -quiet -geometry ");;
    cmd.append(QString("%1:%2").arg(QString::number(ui->view_lb->x())).arg(QString::number(ui->view_lb->y())));
    cmd.append(QString(" -zoom -x %1 -y %2 ").arg(QString::number(ui->view_lb->width()))
               .arg(QString::number(ui->view_lb->height())));
    cmd.append("/mnt/udisk/9.avi");
    play_process->start(cmd);*/

//#else
    qDebug()<<"PC";
    QStringList cmd_list;
    cmd_list<<"-wid";
    cmd_list<<QString::number(ui->view_lb->winId());
    cmd_list<<"/home/gec/9.avi";

    play_process->start("mplayer", cmd_list);
//#endif*/
}

void Adplayer::readPlayMsg()
{

    QString msg = play_process->readLine();
   // qDebug()<<msg;
}

void Adplayer::readWeather()
{
    QString weather_info = wreply->readAll();

    QJsonParseError jerr;
    QJsonDocument jsdoc = QJsonDocument::fromJson(weather_info.toHtmlEscaped(), &jerr);
    if(jerr.error == QJsonParseError::NoError)
    {
        qDebug()<<"this is json";
        if(jsdoc.isObject())
        {
            QJsonObject jsobj = jsdoc.object();
            jsobj = jsobj.value("weatherinfo").toObject();
            qDebug()<<jsobj.value("cityid").toInt();
        }
    }

    qDebug()<<weather_info.toHtmlEscaped();
    //ui->weatherlb->setText();
}

void Adplayer::requestWeather()
{
    wreply = wmasager.get(wrequest);
}
