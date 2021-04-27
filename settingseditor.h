#pragma once

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
    bool isShowToolBar ( ) const ;
    void setShowToolBar ( bool pShow ) ;
    bool isShowStatusBar ( ) const ;
    void setShowStatusBar ( bool pShow ) ;

private:
    Ui::SettingsEditor *ui;
};

