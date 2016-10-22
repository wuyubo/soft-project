#ifndef ADDATE_H
#define ADDATE_H

#include <QTime>
#include <QTimer>
#include <QDate>
#include <QLabel>
#include <QEvent>
#include <QThread>
#include <QPainter>
#include <QFont>


class AdDate : public QWidget
{
    Q_OBJECT
public:
    AdDate(QLabel *_mlabel, QWidget *parent = 0);
    ~AdDate();
    void startTimer();
signals:

public slots:
    void updateTime();
private:
    QLabel *mlabel;

    QTimer *timer;
    QString date;
    QString time;

};

#endif // ADDATE_H
