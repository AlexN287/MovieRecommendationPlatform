#include "QTInterface.h"
#include "Database.h"
#include <QtWidgets/QApplication>
#include "Login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTInterface w;
    w.show();
    return a.exec();
}
