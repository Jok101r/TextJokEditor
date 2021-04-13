#include "textjokeditor.h"
#include "./ui_textjokeditor.h"

TextJokEditor::TextJokEditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TextJokEditor)
{
    ui->setupUi(this);

    ui->action_New->setIcon(QIcon(":/icons/mainform/find"));
    ui->action_New->setShortcut (QKeySequence::New) ;

}

TextJokEditor::~TextJokEditor()
{
    delete ui;
}

