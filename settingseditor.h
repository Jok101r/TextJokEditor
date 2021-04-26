#ifndef SETTINGSEDITOR_H
#define SETTINGSEDITOR_H

#include <QDialog>

namespace Ui {
class SettingsEditor;
}

class SettingsEditor : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsEditor(QWidget *parent = nullptr);
    ~SettingsEditor();

private:
    Ui::SettingsEditor *ui;
};

#endif // SETTINGSEDITOR_H
