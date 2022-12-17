#include "QTInterface.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTInterface w;
    w.show();
    return a.exec();
}
