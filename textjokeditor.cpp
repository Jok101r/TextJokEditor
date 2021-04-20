#include "textjokeditor.h"
#include "./ui_textjokeditor.h"

TextJokEditor::TextJokEditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TextJokEditor)
{
    ui->setupUi(this);

    QPixmap newpic(":/icons/mainform/new3232");
    QPixmap openpic(":/icons/mainform/open3232");
    QPixmap savepic(":/icons/mainform/save3232");
    QPixmap undopic(":/icons/mainform/undo3232");
    QPixmap redopic(":/icons/mainform/redo3232");
    QPixmap cutpic(":/icons/mainform/cut3232");
    QPixmap copypic(":/icons/mainform/copy3232");
    QPixmap pasterpic(":/icons/mainform/paste3232");
    QPixmap quitpic(":/icons/mainform/logout232");

    QAction *newa = new QAction(newpic, "&New", this);
    QAction *open = new QAction(openpic, "&Open", this);
    QAction *save = new QAction(savepic, "&Save", this);
    QAction *quit = new QAction(quitpic, "&Quit", this);

    newa->setShortcut(QKeySequence::New);
    open->setShortcut(QKeySequence::Open);
    save->setShortcut(QKeySequence::Save);
    quit->setShortcut(QKeySequence::Close);

    m_file = menuBar()->addMenu("&File");
    m_file->addAction(newa);
    m_file->addAction(open);
    m_file->addAction(save);
    m_file->addSeparator();
    m_file->addAction(quit);


    QAction *undo = new QAction(undopic, "&Undo", this);
    QAction *redo = new QAction(redopic, "&Redo", this);
    QAction *cut = new QAction(cutpic, "&Cut", this);
    QAction *copy = new QAction(copypic, "&Copy", this);
    QAction *paste = new QAction(pasterpic, "&Paste", this);

    undo->setShortcut(QKeySequence::Undo);
    redo->setShortcut(QKeySequence::Redo);
    cut->setShortcut(QKeySequence::Cut);
    copy->setShortcut(QKeySequence::Copy);
    paste->setShortcut(QKeySequence::Paste);

    m_edit = menuBar()->addMenu("&Edit");
    m_edit->addAction(undo);
    m_edit->addAction(redo);
    m_edit->addSeparator();
    m_edit->addAction(cut);
    m_edit->addAction(copy);
    m_edit->addAction(paste);

//    ui->action_New->setIcon(QIcon(":/icons/mainform/find"));
//    ui->action_New->setShortcut (QKeySequence::New) ;

    m_toolbar = addToolBar("Mainm_toolbar");


    QAction *newtoolbar = m_toolbar->addAction(newpic, "New file");
    QAction *opentoolbar = m_toolbar->addAction(openpic, "Open file");
    QAction *savetoolbar = m_toolbar->addAction(savepic, "Save file");
    m_toolbar->addSeparator();
    QAction *undotoolbar = m_toolbar->addAction(undopic, "Undo text");
    QAction *redotoolbar = m_toolbar->addAction(redopic, "Redo text");
    m_toolbar->addSeparator();
    QAction *cuttoolbar = m_toolbar->addAction(cutpic, "Cut text");
    QAction *copytoolbar = m_toolbar->addAction(copypic, "Copy text");
    QAction *pastetoolbar = m_toolbar->addAction(pasterpic, "Paste text");

    //это почему-то не работает:(
    //connect(newa, SIGNAL(triggered()), this, SLOT(helov));
    connect(open, &QAction::triggered, this, &TextJokEditor::fileOpen);
    connect(opentoolbar, &QAction::triggered, this, &TextJokEditor::fileOpen);

    connect(save, &QAction::triggered, this, &TextJokEditor::fileSave);
    connect(savetoolbar, &QAction::triggered, this, &TextJokEditor::fileSave);

    connect(newa, &QAction::triggered, this, &TextJokEditor::fileNew);
    connect(newtoolbar, &QAction::triggered, this, &TextJokEditor::fileNew);




}
void TextJokEditor::fileOpen(){

    m_fileNameOpen = QFileDialog::getOpenFileName(this, "Open file PLZ...", QDir::homePath(), "*.txt;; All files (*.*)");

    //в случае пересохранении текстового файла
    m_fileNameSave = m_fileNameOpen;

    if (m_fileNameOpen.isEmpty())
        return;

    QFile file(m_fileNameOpen);
    if(file.exists()){
        file.open(QIODevice::ReadOnly);

        QTextStream in(&file);

        m_textData.clear();
        while (!in.atEnd()) {

            m_textData.push_back(in.read(1));

        }
        ui->textField->setPlainText(m_textData);


    }
    else {
        QMessageBox::warning(this, "File not found", "File not found");
    }


    //QMessageBox::information(this, "Text", " chto proishodit");

}

void TextJokEditor::fileSave()
{

    if (m_fileNameSave.isEmpty()){
        QString m_fileNameSave = QFileDialog::getSaveFileName(this, "Save file...", QDir::homePath(), tr (" *.txt;; All files (*.*)" )) ;

        if(m_fileNameSave.isEmpty())
            return;

        QFile file(m_fileNameSave);
        file.open(QIODevice::Text | QIODevice::WriteOnly);
        if(file.exists()){
            //file.write(m_textData);
            QTextStream out(&file);

//            for(int i=0; i<m_textData.length();i++)
//                out << m_textData[i];
            foreach(auto index, m_textData)
                out << index;
//            while (!in.atEnd()) {

//                m_textData.push_back(in.read(1));

//            }
//            ui->textField->setPlainText(m_textData);

            file.close();


        }
        else {
            QMessageBox::warning(this, "File not found", "File not found");
        }


        QMessageBox::information(this, "Text", m_fileNameSave);
    }
}

void TextJokEditor::fileNew()
{
    //проверка на изменения файла
    if (true){
        m_textData.clear();
        ui->textField->setPlainText(m_textData);

    }else {
        fileSave();
    }
}

TextJokEditor::~TextJokEditor()
{
    delete ui;
}

