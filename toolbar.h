#pragma once

#include "picturemap.h"
#include <QToolBar>
#include <QObject>
#include <QWidget>
#include <QVector>
#include <QtDebug>
#include <QAction>
//#include "textjokeditor.h"


class Toolbar : public QToolBar
{
    Q_OBJECT    

    QVector <QAction*> m_action;
    PictureMap m_picturemap;

public:
    Toolbar(const QString&, QWidget *parent);

    void setToolbar(QToolBar *);
    QVector<QAction *> getAction();

private:


};

