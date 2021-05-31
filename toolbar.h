#pragma once

#include "picturemap.h"
#include <QToolBar>
#include <QObject>
#include <QVector>


class Toolbar : public QObject
{
public:
    Toolbar();

    void setToolbar(QToolBar *);
    QVector<QAction *> getAction();

private:


    QVector <QAction*> m_action;
    PictureMap m_picturemap;
    QToolBar *m_toolbar;
};

