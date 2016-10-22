#include "rollmassege.h"
#include <QDebug>

RollMassege::RollMassege(QWidget *parent) :
    QLabel(parent)
{
    rect.setX(0);
    rect.setY(400);
    rect.setWidth(800);
    rect.setHeight(150);
    setGeometry(rect);
    setStyleSheet(QStringLiteral("background-color: rgb(44, 170, 33);"));
    offset = rect.width();
    txt = "暂无信息";
    timer = new QTimer;
    font_size = 16;
    connect(timer, SIGNAL(timeout()), this, SLOT(updateMsg()));
}

RollMassege::RollMassege(QLabel *_label, QWidget *parent) :
    QLabel(parent)
{
    font_size = 16;
    rect = _label->geometry();
    _label->close();

    rect.setWidth(801);
    rect.setHeight(80);

    setStyleSheet(QStringLiteral("background-color: rgb(44, 170, 33);"));
    setGeometry(rect);
    //setVisible(true);
    //show();

    offset = rect.width();
    txt = "暂无信息";
    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(updateMsg()));

}

//消息显示
void RollMassege::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    static int off = rect.width();

    QFont font;
    font.setPointSize(font_size);
    painter.setFont(font);
    painter.drawText(0+offset, 0+50, QObject::tr(txt.toUtf8()));
    if(offset < 0)
    {
        painter.drawText(0+(off+offset), 0+50, QObject::tr(txt.toUtf8()));
    }
    else
    {
        off = rect.width();
    }
    if(date) date->updateTime();
}
void RollMassege::setDate(AdDate *_date)
{
    date = _date;
}


void RollMassege::startRoll()
{
    timer->start(15);
    qDebug()<<rect.x()<<" "<<rect.y()<<" "<<rect.width();
}

//动态消息更新位置
void RollMassege::updateMsg()
{
    offset--;
    if(offset+txt.length()*font_size < 0) offset = rect.width()-txt.length()*font_size;

    update();
}

void RollMassege::setTxt(QString _txt)
{
    qDebug()<<_txt;
    txt = _txt;
}
