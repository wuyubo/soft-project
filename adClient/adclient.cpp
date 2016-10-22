#include "adclient.h"
#include "ui_adclient.h"
#include <QDebug>

AdClient::AdClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdClient)
{
    ui->setupUi(this);

    date = new AdDate(ui->date_lb, ui->date_lb);
    socket = new AdSocket(this);
    weater = new Weather(ui->weather_lb);
    rollmsg = new RollMassege(this);
    rollmsg->show();


    player_process = new QProcess;

    connect(socket, SIGNAL(playVideo(QString)), this, SLOT(playVideo(QString)));
    connect(socket, SIGNAL(showWeather(QString)), weater, SLOT(showWeather(QString)));
    connect(socket, SIGNAL(setMsg(QString)), rollmsg, SLOT(setTxt(QString)));
    //date->startTimer();
    rollmsg->setDate(date);
    rollmsg->startRoll();

}

AdClient::~AdClient()
{
    delete date;
    delete socket;
    delete weater;
    delete rollmsg;
    delete player_process;
    delete ui;
}

//调用系统mplayer，新开进程播放特定广告
void AdClient::playVideo(QString _vdo)
{
    QString cmd("mplayer -slave -quiet -geometry ");
    cmd.append(QString("%1:%2").arg(QString::number(ui->video_lb->x())).arg(QString::number(ui->video_lb->y())));
    cmd.append(QString(" -zoom -x %1 -y %2 ").arg(QString::number(ui->video_lb->width()))
               .arg(QString::number(ui->video_lb->height())));
    cmd.append("./video/");
    cmd.append(_vdo);

    if(player_process->state())
    {
        player_process->close();
    }
    qDebug()<<cmd;
    player_process->start(cmd);
}
