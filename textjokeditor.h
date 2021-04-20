#pragma once

#include <QMainWindow>
#include <QAction>
#include <QToolBar>
#include <QPixmap>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui { class TextJokEditor; }
QT_END_NAMESPACE

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

private:
    QToolBar *m_toolbar;
    QMenu *m_file;
    QMenu *m_edit;

    QString m_textData = " text100";

    QString m_fileNameOpen;
    QString m_fileNameSave;

    Ui::TextJokEditor *ui;
};
