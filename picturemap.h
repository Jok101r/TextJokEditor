#pragma once

#include <QPixmap>
#include <QVector>


class PictureMap
{
public:
    PictureMap();
    QVector<QPixmap> getPictureIcon();


private:
    QVector <QPixmap> m_pictureIcon;


};

