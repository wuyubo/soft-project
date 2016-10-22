#ifndef ADSEVER_H
#define ADSEVER_H

#include <QMainWindow>
#include <QProcess>
#include "adtcp.h"
#include "addate.h"
#include "weather.h"
#include "advideo.h"

namespace Ui {
class AdSever;
}

class AdSever : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdSever(QWidget *parent = 0);
    ~AdSever();
    static QString current_msg;
    void updateVideo();
    void playVideo(QString vdo);
signals:
    void broadcast(QString msg);
    void getWeather(QString city);

private slots:
    void on_broast_msg_bt_clicked();

    void on_set_city_bt_clicked();

    void on_ad_lw_clicked(const QModelIndex &index);

    void videoFinish();

    void on_clear_msg_bt_clicked();

private:
    Ui::AdSever *ui;
    AdTcp *tcpsever;
    AdDate *date;
    Weather *weather;
    AdVideo *video;
    QStringList video_list;
    int video_index;
    QProcess *player_process;
};

#endif // ADSEVER_H
