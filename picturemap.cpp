#include "picturemap.h"

PictureMap::PictureMap()
{

    QPixmap newpic(":/icons/mainform/new3232");
    QPixmap openpic(":/icons/mainform/open3232");
    QPixmap savepic(":/icons/mainform/save3232");
    QPixmap undopic(":/icons/mainform/undo3232");
    QPixmap redopic(":/icons/mainform/redo3232");
    QPixmap cutpic(":/icons/mainform/cut3232");
    QPixmap copypic(":/icons/mainform/copy3232");
    QPixmap pasterpic(":/icons/mainform/paste3232");
    QPixmap quitpic(":/icons/mainform/logout3232");
    QPixmap setpic(":/icons/mainform/settings3232");


    m_pictureIcon.push_back(newpic);
    m_pictureIcon.push_back(openpic);
    m_pictureIcon.push_back(savepic);
    m_pictureIcon.push_back(undopic);
    m_pictureIcon.push_back(redopic);
    m_pictureIcon.push_back(cutpic);
    m_pictureIcon.push_back(copypic);
    m_pictureIcon.push_back(pasterpic);
    m_pictureIcon.push_back(quitpic);
    m_pictureIcon.push_back(setpic);
}

QVector<QPixmap> PictureMap::getPictureIcon()
{
    return m_pictureIcon;
}
