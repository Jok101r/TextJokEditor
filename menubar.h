#pragma once

#include "picturemap.h"
#include <QAction>
#include <QPixmap>
#include <QObject>
#include <QMenu>
#include <QMenuBar>
#include <QVector>


class MenuBar : public QObject
{

public:
    MenuBar();

    void setFile(QMenu *);
    void setEdit(QMenu *);
    void setSettings(QMenu *);

    QVector<QAction*> getAction();


private:
    PictureMap m_picturemap;

    QVector<QAction*> m_action;
    QMenu *m_file;
    QMenu *m_edit;
    QMenu *m_settings;
};
