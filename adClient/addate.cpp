#include "addate.h"
#include <QDebug>

AdDate::AdDate(QLabel *_mlabel, QWidget *parent):
    QWidget(parent)
{
    mlabel = _mlabel;
    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
}

AdDate::~AdDate()
{

}

void AdDate::startTimer()
{
    timer->start(1000);
}


void  AdDate::updateTime()
{
    date = QDate::currentDate().toString("yy-MM-dd");
    time =  QTime::currentTime().toString("hh:mm:ss");
    mlabel->setText(date+"\n"+time);
}

