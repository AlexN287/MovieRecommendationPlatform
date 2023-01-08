#include "QTInterface.h"
#include "QMessageBox"

QTInterface::QTInterface(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.menuBar->hide();
    ui.stackedWidget->setCurrentIndex(0);
}

QTInterface::~QTInterface()
{}

void QTInterface::on_pushButton_login_clicked()
{
    std::string username = ui.lineEdit_username->text().toStdString();
    std::string password = ui.lineEdit_password->text().toStdString();
    if (username == "test" && password == "test") {
        ui.stackedWidget->setCurrentIndex(2);
        ui.menuBar->show();
        ui.lineEdit_username->clear();
        ui.lineEdit_password->clear();
    }
    else
        QMessageBox::warning(this, "Login", "User or password incorrect.");
}
void QTInterface::on_pushButton_signUp_clicked() {
    ui.stackedWidget->setCurrentIndex(1);
    ui.lineEdit_username->clear();
    ui.lineEdit_password->clear();
}
void QTInterface::on_pushButton_back_clicked() {
    ui.stackedWidget->setCurrentIndex(0);
}
void QTInterface::on_checkBox_male_stateChanged(int arg) {
    if (arg != 0)
        ui.checkBox_female->setChecked(0);
}
void QTInterface::on_checkBox_female_stateChanged(int arg) {
    if (arg != 0)
        ui.checkBox_male->setChecked(0);
}
void QTInterface::on_actionSign_Out_3_triggered() {
    ui.stackedWidget->setCurrentIndex(0);
}
void QTInterface::on_pushButton_change_username_clicked() {
    std::string username = ui.lineEdit_username_account->text().toStdString();
    //check if username is in database and change it
}
void QTInterface::on_pushButton_change_password_clicked() {
    std::string password = ui.lineEdit_password_account->text().toStdString();
    //change password in database
}
void QTInterface::on_pushButton_delete_account_clicked() {
    //delete the account from the database
}
void QTInterface::on_actionAccount_triggered() {
    ui.stackedWidget->setCurrentIndex(6);
}