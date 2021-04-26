#include "settingseditor.h"
#include "ui_settingseditor.h"

SettingsEditor::SettingsEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsEditor)
{
    ui->setupUi(this);
}

SettingsEditor::~SettingsEditor()
{
    delete ui;
}
