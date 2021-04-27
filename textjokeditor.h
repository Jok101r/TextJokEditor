#pragma once

#include <QMainWindow>
#include <QAction>
#include <QToolBar>
#include <QPixmap>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QSettings>


QT_BEGIN_NAMESPACE
namespace Ui { class TextJokEditor; }
QT_END_NAMESPACE

class SettingsEditor;

class TextJokEditor : public QMainWindow
{
    Q_OBJECT

public:
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

    void showPreferencesDialog( ) ;
    void slotPreferencesAccepted();

private:
    QToolBar *m_toolbar;
    QMenu *m_file;
    QMenu *m_edit;
    QMenu *m_settings;

    QString m_textData;

    QString m_fileNameOpen;
    QString m_fileNameSave;

    bool m_isNewFile;

    Ui::TextJokEditor *ui;

    void updateTitle(QString);

    SettingsEditor *m_SettingsEditor;

    void readSettings();
    void writeSettings();
    void applySettings();


};
