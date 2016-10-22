#include "advideo.h"
#include <QDebug>

QString AdVideo::current_vdo ="";

AdVideo::AdVideo(const QString & _path)
{
    path = _path;
}

//获取要播放广告单的视频名单列表
QStringList AdVideo::getVideoName()
{
    dir = new QDir(path);
    QStringList filter, name_list;
    int count, i;
    filter<<"*.avi";
    dir->setNameFilters(filter);
    video_list =new QList<QFileInfo>(dir->entryInfoList((filter)));
    count = video_list->count();
    for(i = 0; i < count; i++)
    {
        name_list<<video_list->at(i).fileName();
    }

    delete dir;
    return name_list;
}
