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

bool SettingsEditor::isShowToolBar ( ) const
{
    return ui->showToolbarCheckBox->isChecked();
}
void SettingsEditor::setShowToolBar ( bool pShow )
{
    ui->showToolbarCheckBox->setChecked(pShow);
}
bool SettingsEditor::isShowStatusBar( ) const
{
    return ui->showStatusBarCheckBox->isChecked();
}
void SettingsEditor:: setShowStatusBar ( bool pShow )
{
    ui->showStatusBarCheckBox->setChecked(pShow);
}
