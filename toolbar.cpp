#include "toolbar.h"

Toolbar::Toolbar(const QString &title, QWidget *parent)
    :QToolBar(title, parent)
{

    QAction *newtoolbar = addAction(m_picturemap.getPictureIcon()[0], "Open file");
    QAction *opentoolbar = addAction(m_picturemap.getPictureIcon()[1], "Open file");
    QAction *savetoolbar = addAction(m_picturemap.getPictureIcon()[2], "Save file");
    addSeparator();
    QAction *undotoolbar = addAction(m_picturemap.getPictureIcon()[3], "Undo text");
    QAction *redotoolbar = addAction(m_picturemap.getPictureIcon()[4], "Redo text");
    addSeparator();
    QAction *cuttoolbar = addAction(m_picturemap.getPictureIcon()[5], "Cut text");
    QAction *copytoolbar = addAction(m_picturemap.getPictureIcon()[6], "Copy text");
    QAction *pastetoolbar = addAction(m_picturemap.getPictureIcon()[7], "Paste text");

    m_action.push_back(newtoolbar);
    m_action.push_back(opentoolbar);
    m_action.push_back(savetoolbar);
    m_action.push_back(undotoolbar);
    m_action.push_back(redotoolbar);
    m_action.push_back(cuttoolbar);
    m_action.push_back(copytoolbar);
    m_action.push_back(pastetoolbar);


}

QVector<QAction *> Toolbar::getAction()
{
    return m_action;
}

