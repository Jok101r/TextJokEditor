#include "toolbar.h"

Toolbar::Toolbar()
{
//    m_toolbar = addToolBar("Main toolbar");

    QAction *newtoolbar = m_toolbar->addAction(m_picturemap.getPictureIcon()[0], "New file");
    QAction *opentoolbar = m_toolbar->addAction(m_picturemap.getPictureIcon()[1], "Open file");
    QAction *savetoolbar = m_toolbar->addAction(m_picturemap.getPictureIcon()[2], "Save file");
    m_toolbar->addSeparator();
    QAction *undotoolbar = m_toolbar->addAction(m_picturemap.getPictureIcon()[3], "Undo text");
    QAction *redotoolbar = m_toolbar->addAction(m_picturemap.getPictureIcon()[4], "Redo text");
    m_toolbar->addSeparator();
    QAction *cuttoolbar = m_toolbar->addAction(m_picturemap.getPictureIcon()[5], "Cut text");
    QAction *copytoolbar = m_toolbar->addAction(m_picturemap.getPictureIcon()[6], "Copy text");
    QAction *pastetoolbar = m_toolbar->addAction(m_picturemap.getPictureIcon()[7], "Paste text");

    m_action.push_back(newtoolbar);
    m_action.push_back(opentoolbar);
    m_action.push_back(savetoolbar);
    m_action.push_back(undotoolbar);
    m_action.push_back(redotoolbar);
    m_action.push_back(cuttoolbar);
    m_action.push_back(copytoolbar);
    m_action.push_back(pastetoolbar);


}

void Toolbar::setToolbar(QToolBar *toolbar)
{
    m_toolbar = toolbar;
}

QVector<QAction *> Toolbar::getAction()
{
    return m_action;
}
