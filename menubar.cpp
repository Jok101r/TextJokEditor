#include "menubar.h"

MenuBar::MenuBar()
{
    //меню File
    QAction *newa = new QAction(m_picturemap.getPictureIcon()[0], "&New", this);
    QAction *open = new QAction(m_picturemap.getPictureIcon()[1], "&Open", this);
    QAction *save = new QAction(m_picturemap.getPictureIcon()[2], "&Save", this);
    QAction *quit = new QAction(m_picturemap.getPictureIcon()[8], "&Quit", this);

    m_action.push_back(newa);
    m_action.push_back(open);
    m_action.push_back(save);
    m_action.push_back(quit);
    //горячие клавижши
    newa->setShortcut(QKeySequence::New);
    open->setShortcut(QKeySequence::Open);
    save->setShortcut(QKeySequence::Save);
    quit->setShortcut(QKeySequence::Close);

    //отображение
    //m_file = menuBar()->addMenu("&File");
    m_file->addAction(newa);
    m_file->addAction(open);
    m_file->addAction(save);
    m_file->addSeparator();
    m_file->addAction(quit);

    //меню Edit
    QAction *undo = new QAction(m_picturemap.getPictureIcon()[3], "&Undo", this);
    QAction *redo = new QAction(m_picturemap.getPictureIcon()[4], "&Redo", this);
    QAction *cut = new QAction(m_picturemap.getPictureIcon()[5], "&Cut", this);
    QAction *copy = new QAction(m_picturemap.getPictureIcon()[6], "&Copy", this);
    QAction *paste = new QAction(m_picturemap.getPictureIcon()[7], "&Paste", this);

    m_action.push_back(undo);
    m_action.push_back(redo);
    m_action.push_back(cut);
    m_action.push_back(copy);
    m_action.push_back(paste);


    //горячие клавиши
    undo->setShortcut(QKeySequence::Undo);
    redo->setShortcut(QKeySequence::Redo);
    cut->setShortcut(QKeySequence::Cut);
    copy->setShortcut(QKeySequence::Copy);
    paste->setShortcut(QKeySequence::Paste);

    //отображение
    //m_edit = menuBar()->addMenu("&Edit");
    m_edit->addAction(undo);
    m_edit->addAction(redo);
    m_edit->addSeparator();
    m_edit->addAction(cut);
    m_edit->addAction(copy);
    m_edit->addAction(paste);

    //Меню Settings
    QAction *settings = new QAction(m_picturemap.getPictureIcon()[9], "&Settings", this);

    m_action.push_back(settings);

    //горячие клавиши
    //проверить работу на маке
    settings->setShortcut(tr("CTRL+P"));

    //отображение
    //m_settings = menuBar()->addMenu("&Settings");
    m_settings->addAction(settings);



}

void MenuBar::setFile(QMenu *menuFile)
{
    m_file = menuFile;
}

void MenuBar::setEdit(QMenu *menuEdit)
{
    m_edit = menuEdit;
}

void MenuBar::setSettings(QMenu *menuSet)
{
    m_settings = menuSet;
}

QVector<QAction*> MenuBar::getAction()
{
    return m_action;
}
