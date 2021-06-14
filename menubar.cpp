#include "menubar.h"

MenuBar::MenuBar(QWidget *parent)
    : QMenuBar(parent)
{
    //меню File
    QAction *newa = new QAction(m_picturemap.getPictureIcon()[0], "&New");
    QAction *open = new QAction(m_picturemap.getPictureIcon()[1], "&Open");
    QAction *save = new QAction(m_picturemap.getPictureIcon()[2], "&Save");
    QAction *quit = new QAction(m_picturemap.getPictureIcon()[8], "&Quit");

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
    m_file = new QMenu ("&File");
    m_file->addAction(newa);
    m_file->addAction(open);
    m_file->addAction(save);
    m_file->addSeparator();
    m_file->addAction(quit);
    addMenu(m_file);



    //меню Edit
    QAction *undo = new QAction(m_picturemap.getPictureIcon()[3], "&Undo");
    QAction *redo = new QAction(m_picturemap.getPictureIcon()[4], "&Redo");
    QAction *cut = new QAction(m_picturemap.getPictureIcon()[5], "&Cut");
    QAction *copy = new QAction(m_picturemap.getPictureIcon()[6], "&Copy");
    QAction *paste = new QAction(m_picturemap.getPictureIcon()[7], "&Paste");

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
    m_edit = new QMenu ("&Edit");
    m_edit->addAction(undo);
    m_edit->addAction(redo);
    m_edit->addSeparator();
    m_edit->addAction(cut);
    m_edit->addAction(copy);
    m_edit->addAction(paste);
    addMenu(m_edit);

    //Меню Settings
    QAction *settings = new QAction (m_picturemap.getPictureIcon()[9], "&Settings");
    m_action.push_back(settings);

    //горячие клавиши
    settings->setShortcut(tr("CTRL+P"));
    //отображение
    m_settings = new QMenu ("&Settings");
    m_settings->addAction(settings);
    addMenu(m_settings);



}

QVector<QAction*> MenuBar::getAction()
{
    return m_action;
}
