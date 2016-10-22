#include "adsever.h"
#include "ui_adsever.h"
#include <QDebug>
#include <QMessageBox>

AdSever::AdSever(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdSever)
{
    ui->setupUi(this);

    date = new AdDate(ui->date_lb);
    tcpsever = new AdTcp(ui->client_lw);
    video = new AdVideo("./video");
    weather = new Weather(ui->weather_lb, ui->city_cb, ui->distict_cb);
    player_process = new QProcess;

    connect(ui->city_cb, SIGNAL(currentIndexChanged(QString)), weather, SLOT(findArea(QString)));
    connect(this, SIGNAL(getWeather(QString)), weather, SLOT(getWeather(QString)));
    connect(weather, SIGNAL(broadcast(QString)), tcpsever, SLOT(broadcastMsg(QString)));
    connect(this, SIGNAL(broadcast(QString)), tcpsever, SLOT(broadcastMsg(QString)));
    connect(player_process, SIGNAL(finished(int)), this, SLOT(videoFinish()));

    date->start();

    updateVideo();
    video_index = 0;
    playVideo(video_list[0]);

}

AdSever::~AdSever()
{
    delete date;
    delete tcpsever;
    delete weather;
    delete ui;
}

void AdSever::on_broast_msg_bt_clicked()
{
    QString msg = ui->msg_te->toPlainText();

    AdTcp::current_msg = msg;
    if(!msg.isEmpty())
    {
        emit broadcast(QString::number(MASSEGE)+"|"+ msg);
        ui->msg_lw->addItem(msg);
    }

}

void AdSever::on_set_city_bt_clicked()
{
    QString city = ui->distict_cb->currentText();
    emit getWeather(city);
}

void AdSever::updateVideo()
{
    QStringList name;
    video_list.clear();
    video_list = video->getVideoName();

    ui->ad_lw->clear();

    for(int i=0; i<video_list.count(); i++)
    {
        name = video_list[i].split(".");
        ui->ad_lw->addItem(name[0]);
    }

}


void AdSever::playVideo(QString vdo)
{
    QStringList name = vdo.split(".");
    ui->vdoname_lb->setText(name[0]);

    QStringList cmd;
    cmd<<"-wid";
    cmd<<QString::number(ui->video_lb->winId());
    cmd<<"./video/"+vdo;

    AdVideo::current_vdo = vdo;
    qDebug()<<vdo;

    if(player_process->state())
    {
        player_process->close();
        connect(player_process, SIGNAL(finished(int)), this, SLOT(videoFinish()));
    }
    player_process->start("mplayer", cmd);

    ui->ad_lw->setItemSelected(ui->ad_lw->item(video_index), true);
    emit broadcast(QString::number(VIDEO)+"|"+vdo);

}



void AdSever::on_ad_lw_clicked(const QModelIndex &index)
{
    video_index = index.row();
    qDebug()<<index.row();
    disconnect(player_process, SIGNAL(finished(int)), this, SLOT(videoFinish()));
    playVideo(video_list[video_index]);
}



void AdSever::videoFinish()
{
    video_index++;
    if(video_index == video_list.size())
        video_index = 0;
    playVideo(video_list[video_index]);

}


void AdSever::on_clear_msg_bt_clicked()
{
    ui->msg_te->clear();
}
