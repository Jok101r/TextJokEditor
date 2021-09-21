#include "textjokeditor.h"

#include "menubar.h"
#include "toolbar.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TextJokEditor w;
    w.setWindowIcon(QIcon(":/icons/mainform/filetxt"));
    w.show();
    return a.exec();
}
