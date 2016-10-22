#ifndef ADCLIENT_H
#define ADCLIENT_H

#include <QMainWindow>
#include "addate.h"
#include "adsocket.h"
#include "weather.h"
#include "rollmassege.h"
#include "weather.h"
#include <QLabel>
#include <QProcess>

namespace Ui {
class AdClient;
}

class AdClient : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdClient(QWidget *parent = 0);
    ~AdClient();

public slots:
    void playVideo(QString _vdo);

private:
    Ui::AdClient *ui;
    AdDate *date;
    AdSocket *socket;
    Weather *weater;
    RollMassege *rollmsg;
    QProcess *player_process;
};

#endif // ADCLIENT_H
