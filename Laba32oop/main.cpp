#include "Laba32oop.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Numbers* numbers = new Numbers(&a);
    MainWindow w(numbers);
    w.show();
    return a.exec();
}
