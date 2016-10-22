#ifndef ADVIDEO_H
#define ADVIDEO_H

#include <QDir>

class AdVideo
{
public:
    AdVideo(const QString & _path);
    QStringList getVideoName();
    static QString current_vdo;
private:
    QString path;
    QDir *dir;
    QList<QFileInfo> *video_list;
};

#endif // ADVIDEO_H
