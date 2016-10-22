#ifndef ROLLMASSEGE_H
#define ROLLMASSEGE_H

#include <QLabel>
#include <QEvent>
#include <QTimer>
#include <QRect>
#include <QPainter>
#include <QFont>
#include "addate.h"

class RollMassege : public QLabel
{
    Q_OBJECT
public:
    explicit RollMassege(QWidget *parent = 0);
    explicit RollMassege(QLabel *_label, QWidget *parent = 0);

    void paintEvent(QPaintEvent *event);
    void startRoll();
    void setDate(AdDate *_date);
signals:

public slots:
    void updateMsg();
    void setTxt(QString _txt);
private:
    QString txt;
    QRect rect;
    int offset;
    QTimer *timer;
    AdDate *date;
    int font_size;
};

#endif // ROLLMASSEGE_H
