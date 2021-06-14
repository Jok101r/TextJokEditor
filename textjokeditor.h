#pragma once

#include <QMainWindow>
#include <QPixmap>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QSettings>
#include <QShortcut>
#include <QLabel>
#include "menubar.h"
#include "toolbar.h"




QT_BEGIN_NAMESPACE
namespace Ui { class TextJokEditor; }
QT_END_NAMESPACE

class SettingsEditor;

class TextJokEditor : public QMainWindow
{
    Q_OBJECT

    Toolbar *m_toolbar;
    MenuBar *m_menu;
    QLabel *label;

    QString m_textData;
    QString out = "Number of word %1, number of characters: %2";
    QString m_fileNameOpen;
    QString m_fileNameSave;
    bool m_isNewFile;

    Ui::TextJokEditor *ui;

    SettingsEditor *m_SettingsEditor;

public:
    TextJokEditor(QWidget *parent = nullptr);
    ~TextJokEditor();

public slots:
    void fileOpen();
    void fileSave();
    void fileNew();
    void textCopy();
    void textPaste();
    void textCut();
    void textUndo();
    void textRedo();
    void countWS();

    void showPreferencesDialog( ) ;
    void slotPreferencesAccepted();

private:

    void updateTitle(QString);
    void outPutStatusBar(int,int);

    void readSettings();
    void writeSettings();
    void applySettings();



};
