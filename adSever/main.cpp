#include "adsever.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec *codec;
    codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);

    AdSever w;
    w.show();

    return a.exec();
}
