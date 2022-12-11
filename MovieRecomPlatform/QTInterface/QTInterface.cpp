#include "QTInterface.h"
#include "QMessageBox"

QTInterface::QTInterface(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

QTInterface::~QTInterface()
{}

void QTInterface::on_pushButton_login_clicked()
{

    std::string username = ui.lineEdit_username->text().toStdString();
    std::string password = ui.lineEdit_password->text().toStdString();
    if (username == "Test" && password == "Test") {
        QMessageBox::information(this, "Login", "da");
    }
    else
    {
        QMessageBox::warning(this, "Login", "nu");
    }
}
