#include "QTInterface.h"
#include "QMessageBox"

QTInterface::QTInterface(QWidget* parent)
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
    if (username == "test" && password == "test") {
        //QMessageBox::information(this, "Login", "da");
        ui.stackedWidget->setCurrentIndex(1);
    }
    else
    {
        QMessageBox::warning(this, "Login", "nu");
    }
}