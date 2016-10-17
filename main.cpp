#include "adplayer.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Adplayer w;
    w.show();

    return a.exec();
}
