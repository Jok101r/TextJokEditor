#include "textjokeditor.h"
#include "settingseditor.h"

#include "./ui_textjokeditor.h"


//TextJokEditor::TextJokEditor(MenuBar &menubar, Toolbar &toolbar, QWidget *parent)
//    : QMainWindow(parent)
//    , m_menu(menubar)
//    , m_toolbar(toolbar)
//    , ui(new Ui::TextJokEditor)
TextJokEditor::TextJokEditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TextJokEditor)
     // добавление диалога в программу
    , m_SettingsEditor (new SettingsEditor(this))
{

    ui->setupUi(this);
    //статический вывод в статусбаре
    label = new QLabel (this);

     m_menu.setFile(menuBar()->addMenu("&File"));
     m_menu.setEdit(menuBar()->addMenu("&Edit"));
     m_menu.setSettings(menuBar()->addMenu("&Settings"));


     //m_menu = new MenuBar(this);
//    QPixmap newpic(":/icons/mainform/new3232");
//    QPixmap openpic(":/icons/mainform/open3232");
//    QPixmap savepic(":/icons/mainform/save3232");
//    QPixmap undopic(":/icons/mainform/undo3232");
//    QPixmap redopic(":/icons/mainform/redo3232");
//    QPixmap cutpic(":/icons/mainform/cut3232");
//    QPixmap copypic(":/icons/mainform/copy3232");
//    QPixmap pasterpic(":/icons/mainform/paste3232");
//    QPixmap quitpic(":/icons/mainform/logout3232");
//    QPixmap setpic(":/icons/mainform/settings3232");

//    //меню File
//    QAction *newa = new QAction(newpic, "&New", this);
//    QAction *open = new QAction(openpic, "&Open", this);
//    QAction *save = new QAction(savepic, "&Save", this);
//    QAction *quit = new QAction(quitpic, "&Quit", this);

//    //горячие клавиши
//    newa->setShortcut(QKeySequence::New);
//    open->setShortcut(QKeySequence::Open);
//    save->setShortcut(QKeySequence::Save);
//    quit->setShortcut(QKeySequence::Close);

//    //отображение
//    m_file = menuBar()->addMenu("&File");
//    m_file->addAction(newa);
//    m_file->addAction(open);
//    m_file->addAction(save);
//    m_file->addSeparator();
//    m_file->addAction(quit);


//    //меню Edit
//    QAction *undo = new QAction(undopic, "&Undo", this);
//    QAction *redo = new QAction(redopic, "&Redo", this);
//    QAction *cut = new QAction(cutpic, "&Cut", this);
//    QAction *copy = new QAction(copypic, "&Copy", this);
//    QAction *paste = new QAction(pasterpic, "&Paste", this);

//    //горячие клавиши
//    undo->setShortcut(QKeySequence::Undo);
//    redo->setShortcut(QKeySequence::Redo);
//    cut->setShortcut(QKeySequence::Cut);
//    copy->setShortcut(QKeySequence::Copy);
//    paste->setShortcut(QKeySequence::Paste);

//     //отображение
//      m_edit = menuBar()->addMenu("&Edit");
//    m_edit->addAction(undo);
//    m_edit->addAction(redo);
//    m_edit->addSeparator();
//    m_edit->addAction(cut);
//    m_edit->addAction(copy);
//    m_edit->addAction(paste);

//    //Меню Settings
//    QAction *settings = new QAction(setpic, "&Settings", this);

//    //горячие клавиши
//    //проверить работу на маке
//    settings->setShortcut(tr("CTRL+P"));

//    //отображение
//      m_settings = menuBar()->addMenu("&Settings");
//    m_settings->addAction(settings);


    m_toolbar.setToolbar(addToolBar("Main toolbar"));

//    QAction *newtoolbar = m_toolbar->addAction(newpic, "New file");
//    QAction *opentoolbar = m_toolbar->addAction(openpic, "Open file");
//    QAction *savetoolbar = m_toolbar->addAction(savepic, "Save file");
//    m_toolbar->addSeparator();
//    QAction *undotoolbar = m_toolbar->addAction(undopic, "Undo text");
//    QAction *redotoolbar = m_toolbar->addAction(redopic, "Redo text");
//    m_toolbar->addSeparator();
//    QAction *cuttoolbar = m_toolbar->addAction(cutpic, "Cut text");
//    QAction *copytoolbar = m_toolbar->addAction(copypic, "Copy text");
//    QAction *pastetoolbar = m_toolbar->addAction(pasterpic, "Paste text");

    //подключение кнопок в Qtoolbar и Qmenu к слоту

    //это почему-то не работает:(
    //connect(newa, SIGNAL(triggered()), this, SLOT(helov));

    //new
    connect(m_menu.getAction()[0], &QAction::triggered, this, &TextJokEditor::fileNew);
    connect(m_toolbar.getAction()[0], &QAction::triggered, this, &TextJokEditor::fileNew);

    //open
    connect(m_menu.getAction()[1], &QAction::triggered, this, &TextJokEditor::fileOpen);
    connect(m_toolbar.getAction()[1], &QAction::triggered, this, &TextJokEditor::fileOpen);

    //save
    connect(m_menu.getAction()[2], &QAction::triggered, this, &TextJokEditor::fileSave);
    connect(m_toolbar.getAction()[2], &QAction::triggered, this, &TextJokEditor::fileSave);

    //quit
    connect(m_menu.getAction()[3], &QAction::triggered, this, &QApplication::quit);

    //undo
    connect(m_menu.getAction()[4], &QAction::triggered, this, &TextJokEditor::textUndo);
    connect(m_toolbar.getAction()[3], &QAction::triggered, this, &TextJokEditor::textUndo);

    //redo
    connect(m_menu.getAction()[5], &QAction::triggered, this, &TextJokEditor::textRedo);
    connect(m_toolbar.getAction()[4], &QAction::triggered, this, &TextJokEditor::textRedo);

    //cut
    connect(m_menu.getAction()[6], &QAction::triggered, this, &TextJokEditor::textCut);
    connect(m_toolbar.getAction()[5], &QAction::triggered, this, &TextJokEditor::textCut);

    //copy
    connect(m_menu.getAction()[7], &QAction::triggered, this, &TextJokEditor::textCopy);
    connect(m_toolbar.getAction()[6], &QAction::triggered, this, &TextJokEditor::textCopy);

    //paste
    connect(m_menu.getAction()[8], &QAction::triggered, this, &TextJokEditor::textCopy);
    connect(m_toolbar.getAction()[7], &QAction::triggered, this, &TextJokEditor::textPaste);






    //подключение сигнала настроек к слоту отображение настроек
    connect(m_menu.getAction()[9], &QAction::triggered, this, &TextJokEditor::showPreferencesDialog);


    //connect(m_SettingsEditor,SIGNAL(accepted()), this, SLOT(slotPreferencesAccepted()));
    connect(m_SettingsEditor, &QDialog::accepted, this, &TextJokEditor::slotPreferencesAccepted);

    //подключение сигнала настроек к слоту отображение настроек
    connect(ui->textField, SIGNAL(textChanged()), this, SLOT(countWS()));

}
//слот открытия файла
void TextJokEditor::fileOpen(){

    m_fileNameOpen = QFileDialog::getOpenFileName(this, "Open file ...", QDir::homePath(), "*.txt;; All files (*.*)");

    //в случае пересохранении текстового файла
    m_fileNameSave = m_fileNameOpen;

    if (m_fileNameOpen.isEmpty())
        return;

    QFile file(m_fileNameOpen);


    updateTitle(file.fileName());

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

    //QMessageBox::information(this, "Text", "test");

}


//запись в файл

void openFileWrite(QFile &file, QString &textData, QWidget *wid){

    file.open(QIODevice::Text | QIODevice::WriteOnly);
    if(file.exists()){
        QTextStream out(&file);
        foreach(auto index, textData)
            out << index;
        file.close();
    }
    else {
        QMessageBox::warning(wid, "File not found", "File not found");

    }

}
//слот сохранения в файл
void TextJokEditor::fileSave()
{

    m_textData = ui->textField->toPlainText();

    if (m_fileNameSave.isEmpty()){
        QString m_fileNameSave = QFileDialog::getSaveFileName(this, "Save file...", QDir::homePath(), tr (" *.txt;; All files (*.*)" )) ;

        if(m_fileNameSave.isEmpty())
            return;

        QFile file(m_fileNameSave);

        openFileWrite(file, m_textData, this);
    }
    else{

        QFile file(m_fileNameSave);
        file.remove();
        openFileWrite(file,m_textData, this);
    }
}

//создание пустого файла с проверкой на сохранение файла
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

//стандртые слоты при работе с текстом
void TextJokEditor::textCopy()
{
    ui->textField->copy();
}

void TextJokEditor::textPaste()
{
    ui->textField->paste();
}

void TextJokEditor::textCut()
{
    ui->textField->cut();
}

void TextJokEditor::textUndo()
{
    ui->textField->undo();
}
void TextJokEditor::textRedo()
{
    ui->textField->redo();
}

//вывод в statusbar
void TextJokEditor::outPutStatusBar(int first, int second)
{

    //ui->statusbar->showMessage(out.arg(first).arg(second));
    label->setText(out.arg(first).arg(second));
    ui->statusbar->addWidget(label);
}

//подсчет количества слов и символов
void TextJokEditor::countWS()
{
    int countWord;
    int countSymbol = 0;

    //countWord = ui->textField->toPlainText().split((" "), Qt::SkipEmptyParts).count();
    //countWord += ui->textField->toPlainText().split(("\n"), Qt::SkipEmptyParts).count() - 1;
    if (countWord < 0)
        countWord = 0;
    countSymbol = ui->textField->toPlainText().length();

    outPutStatusBar(countWord,countSymbol);

}

//изменения титульника файла
void TextJokEditor::updateTitle(QString fileName)
{
    QString title = QString("TextJokEditor - %1").arg(fileName); //устанавливаем заголовок окна
    setWindowTitle( title ) ;
}
//https://qthelper.ru/%D1%81%D0%BE%D1%85%D1%80%D0%B0%D0%BD%D0%B5%D0%BD%D0%B8%D0%B5-%D0%BD%D0%B0%D1%81%D1%82%D1%80%D0%BE%D0%B5%D0%BA-qsettings/

//чтение сохраненных настроек
void TextJokEditor::readSettings()
{
    //Указываем,где хранились настройки.
    //QSettings::NativeFormat — в формате определенном системой
    //QSettings::UserScope — настройки для каждого пользователя отдельно.
    QSettings Settings(QSettings::NativeFormat, QSettings::UserScope,"",qApp->applicationName());
    //Открываем группу настроек
    Settings.beginGroup("SETTINGS_GROUP_VIEW");
    //Читаемнастройки
    bool ShowToolBar = Settings.value("SETTING_SHOW_TOOLBAR",m_SettingsEditor->isShowToolBar()).toBool();
    m_SettingsEditor->setShowToolBar(ShowToolBar);
    bool ShowStatusBar= Settings.value("SETTING_SHOW_STATUS_BAR",m_SettingsEditor->isShowStatusBar()).toBool();
    m_SettingsEditor->setShowStatusBar(ShowStatusBar);
}

//запись настроек
void TextJokEditor::writeSettings()
{
    QSettings Settings(QSettings::NativeFormat,QSettings::UserScope,"",qApp->applicationName());
    //Открываем группу настроек
    Settings.beginGroup("SETTINGS_GROUP_VIEW");
    //Записываем настройки
    Settings.setValue("SETTING_SHOW_TOOLBAR", m_SettingsEditor->isShowToolBar());
    Settings.setValue("SETTING_SHOW_STATUS_BAR", m_SettingsEditor->isShowStatusBar());

}

//применение настроек
void TextJokEditor::applySettings()
{
    //Читаем настройки установленые в диалоге и применяем их
    ui->statusbar->setVisible(m_SettingsEditor->isShowStatusBar());
    //m_toolbar->setVisible(m_SettingsEditor->isShowToolBar());
}

TextJokEditor::~TextJokEditor()
{
    delete ui;
}

//отображение формы настроек
void TextJokEditor::showPreferencesDialog()
{
    readSettings();
    //Показываем диалог настроек
    m_SettingsEditor->show();
}

//записать и применить настроек
void TextJokEditor::slotPreferencesAccepted()
{
    writeSettings(); //Записать новые настройки
    applySettings(); //Применить настройки


}

