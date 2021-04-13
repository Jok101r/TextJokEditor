#include "textjokeditor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TextJokEditor w;
    w.show();
    return a.exec();
}
