#include "textjokeditor.h"
#include "settingseditor.h"

#include "./ui_textjokeditor.h"


TextJokEditor::TextJokEditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TextJokEditor)
     // добавление диалога настроек в программу
    , m_SettingsEditor (new SettingsEditor(this))
{

    ui->setupUi(this);
    //статический вывод в статусбаре
    label = new QLabel (this);

    m_toolbar = new Toolbar("Main toolbar", this);
    m_menu = new MenuBar(this);

    setMenuBar(m_menu);
    addToolBar(m_toolbar);
    readSettings();
    applySettings();





    //new
    connect(m_toolbar->getAction()[0], &QAction::triggered, this, &TextJokEditor::fileNew);
    connect(m_menu->getAction()[0], &QAction::triggered, this, &TextJokEditor::fileNew);
   //open
    connect(m_toolbar->getAction()[1], &QAction::triggered, this, &TextJokEditor::fileOpen);
    connect(m_menu->getAction()[1], &QAction::triggered, this, &TextJokEditor::fileOpen);

    //save
    connect(m_toolbar->getAction()[2], &QAction::triggered, this, &TextJokEditor::fileSave);
    connect(m_menu->getAction()[2], &QAction::triggered, this, &TextJokEditor::fileSave);

    //saveAs
    connect(m_menu->getAction()[3], &QAction::triggered, this, &TextJokEditor::fileSaveAs);

    //quit
    connect(m_menu->getAction()[4], &QAction::triggered, this, &QApplication::quit);

    //undo
    connect(m_toolbar->getAction()[3], &QAction::triggered, this, &TextJokEditor::textUndo);
    connect(m_menu->getAction()[5], &QAction::triggered, this, &TextJokEditor::textUndo);

    //redo
    connect(m_toolbar->getAction()[4], &QAction::triggered, this, &TextJokEditor::textRedo);
    connect(m_menu->getAction()[6], &QAction::triggered, this, &TextJokEditor::textRedo);

    //cut
    connect(m_toolbar->getAction()[5], &QAction::triggered, this, &TextJokEditor::textCut);
    connect(m_menu->getAction()[7], &QAction::triggered, this, &TextJokEditor::textCut);

    //copy
   connect(m_toolbar->getAction()[6], &QAction::triggered, this, &TextJokEditor::textCopy);
   connect(m_menu->getAction()[8], &QAction::triggered, this, &TextJokEditor::textCopy);

    //paste
    connect(m_toolbar->getAction()[7], &QAction::triggered, this, &TextJokEditor::textPaste);
    connect(m_menu->getAction()[9], &QAction::triggered, this, &TextJokEditor::textCopy);

//    //подключение сигнала настроек к слоту отображение настроек
    connect(m_menu->getAction()[10], &QAction::triggered, this, &TextJokEditor::showPreferencesDialog);

    connect(m_SettingsEditor, &QDialog::accepted, this, &TextJokEditor::slotPreferencesAccepted);

    //подключение сигнала настроек к слоту отображение настроек
    connect(ui->textField, &QPlainTextEdit::textChanged, this, &TextJokEditor::countWS);

    connect(ui->textField, &QPlainTextEdit::textChanged, this, &TextJokEditor::saveDocument );

}

//создание пустого файла с проверкой на сохранение файла
void TextJokEditor::fileNew()
{
    //проверка на изменения файла
    if (ui->textField->toPlainText().isEmpty())
    {
        m_textData.clear();
        ui->textField->setPlainText(m_textData);
        setWindowTitle("TextJokEditor") ;
        m_isNewFile = true;

    }else
    {
        if(m_isSaveDocument == false)
        {
            fileSave();
//            if(m_isSaveDocument == false)
//            {
//                return;
//            }
            m_textData.clear();
            ui->textField->setPlainText(m_textData);
            setWindowTitle("TextJokEditor") ;
            m_isNewFile = true;
        }
    }
}

//слот открытия файла
void TextJokEditor::fileOpen(){

    if (m_isNewFile == true)
    {
        m_fileNameOpen = QFileDialog::getOpenFileName(this, "Open file ...", QDir::homePath(), "*.txt;; All files (*.*)");

        if (m_fileNameOpen.isEmpty())
        {
            m_isOpenDocument = false;
            return;
        }
        m_isOpenDocument = true;
        //в случае пересохранении текстового файла
        m_fileNameSave = m_fileNameOpen;

        if (m_fileNameOpen.isEmpty())
            return;

        QFile file(m_fileNameOpen);
        updateTitle(file.fileName());

        if(file.exists())
        {

            file.open(QIODevice::ReadWrite);
            QTextStream in(&file);
            m_textData.clear();

            while (!in.atEnd())
            {

                m_textData.push_back(in.read(1));

            }

            ui->textField->setPlainText(m_textData);

            m_isNewFile = false;

        }else
        {
            QMessageBox::warning(this, "File not found", "File not found");
        }
    }else

    //if (m_isNewFile == false)
    {

        //проверка на сохраненный документ
        if (m_isSaveDocument == false)
        {
            fileSave();
        }
        m_isNewFile = true;
        fileOpen();


    }


    //QMessageBox::warning(this, "Warning", "Something wrong....try again");


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

    if (m_fileNameSave.isEmpty())
    {
        fileSaveAs();
    }else
    {
        auto answer = QMessageBox::question(this, "Save?", "Аre you sure you want to save the document?");
        if (answer == QMessageBox::Yes)
        {
            QFile file(m_fileNameSave);
            file.remove();
            openFileWrite(file, m_textData, this);
            m_isSaveDocument = true;
        }
        if (answer == QMessageBox::No)
        {
            m_isSaveDocument = false;
        }
    }


}

void TextJokEditor::fileSaveAs()
{
    m_textData = ui->textField->toPlainText();

    QString m_fileNameSave = QFileDialog::getSaveFileName(this, "Save file...", QDir::homePath(), tr (" *.txt;; All files (*.*)" )) ;

    if(m_fileNameSave.isEmpty())
    {
        m_isSaveDocument = false;
        return;
    }

    QFile file(m_fileNameSave);
    openFileWrite(file, m_textData, this);
    m_isSaveDocument = true;

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
    label->setText(m_out.arg(first).arg(second));
    ui->statusbar->addWidget(label);
}

//подсчет количества слов и символов
void TextJokEditor::countWS()
{
    int countWord;
    int countSymbol = 0;

    countWord = ui->textField->toPlainText().split((" "), QString::SkipEmptyParts).count();
    countWord += ui->textField->toPlainText().split(("\n"), QString::SkipEmptyParts).count() - 1;
    if (countWord < 0)
        countWord = 0;
    countSymbol = ui->textField->toPlainText().length();
    outPutStatusBar(countWord,countSymbol);

}

void TextJokEditor::saveDocument()
{
    m_isSaveDocument = false;
}

//изменения титульника файла
void TextJokEditor::updateTitle(QString fileName)
{
    QString title = QString("TextJokEditor - %1").arg(fileName);
    //устанавливаем заголовок окна
    setWindowTitle( title ) ;
}


//чтение сохраненных настроек
void TextJokEditor::readSettings()
{
    //Указываем,где хранились настройки.
    //QSettings::NativeFormat — в формате определенном системой
    //QSettings::UserScope — настройки для каждого пользователя отдельно.
    //QSettings Settings(QSettings::NativeFormat, QSettings::UserScope,"",qApp->applicationName());
    QSettings Settings("settings.conf", QSettings::IniFormat);
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
    QSettings Settings("settings.conf", QSettings::IniFormat);
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
    m_toolbar->setVisible(m_SettingsEditor->isShowToolBar());
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

