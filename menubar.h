#pragma once

#include "picturemap.h"
#include <QAction>
#include <QPixmap>
#include <QMenu>
#include <QMenuBar>
#include <QVector>


class MenuBar : public QMenuBar
{
    Q_OBJECT

    QMenu *m_file;
    QMenu *m_edit;
    QMenu *m_settings;
public:
    MenuBar(QWidget *parent);

    QVector<QAction*> getAction();


private:
    PictureMap m_picturemap;

    QVector<QAction*> m_action;



};
