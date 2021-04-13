#pragma once

#include <QMainWindow>
#include <QAction>

QT_BEGIN_NAMESPACE
namespace Ui { class TextJokEditor; }
QT_END_NAMESPACE

class TextJokEditor : public QMainWindow
{
    Q_OBJECT

public:
    TextJokEditor(QWidget *parent = nullptr);
    ~TextJokEditor();

private:
    Ui::TextJokEditor *ui;
};
