#pragma once

#include <QMainWindow>
#include <QAction>
#include <QToolBar>
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

public:
    //TextJokEditor(MenuBar &,Toolbar &, QWidget *parent = nullptr);
    TextJokEditor(QWidget *parent = nullptr);
    ~TextJokEditor();

private slots:
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
    
    MenuBar m_menu;
    Toolbar m_toolbar;


//    QToolBar *m_toolbar;
//    QMenu *m_file;
//    QMenu *m_edit;
//    QMenu *m_settings;
    QLabel *label;

    QString m_textData;
    QString out = "Number of word %1, number of characters: %2";
    QString m_fileNameOpen;
    QString m_fileNameSave;
    bool m_isNewFile;

    Ui::TextJokEditor *ui;

    void updateTitle(QString);
    void outPutStatusBar(int,int);

    SettingsEditor *m_SettingsEditor;

    void readSettings();
    void writeSettings();
    void applySettings();



};
