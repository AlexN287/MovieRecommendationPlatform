#include "QTInterface.h"
#include "QMessageBox"
#include <qsignalmapper.h>

QTInterface::QTInterface(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    createMenuBar();
    ui.menuBar->hide();
    ui.stackedWidget->setCurrentIndex(0);
}

QTInterface::~QTInterface()
{}
void QTInterface::createMenuBar() {
    QAction* homeAction = ui.menuBar->addAction("Home");
    connect(homeAction, SIGNAL(triggered()), this, SLOT(homePage()));
    
    QAction* showsAction = ui.menuBar->addAction("TV Shows");
    connect(showsAction, SIGNAL(triggered()), this, SLOT(showsPage()));

    QAction* moviesAction = ui.menuBar->addAction("Movies");
    connect(moviesAction, SIGNAL(triggered()), this, SLOT(moviesPage()));

    QAction* watchlistAction = ui.menuBar->addAction("Watchlist");
    connect(watchlistAction, SIGNAL(triggered()), this, SLOT(watchlistPage()));

    QMenu* profileMenu = ui.menuBar->addMenu("Profile");
    QAction* accountAction = profileMenu->addAction("Account");
    connect(accountAction, SIGNAL(triggered()), this, SLOT(accountPage()));

    QAction* likedMoviesAction = profileMenu->addAction("Liked Movies");
    //connect(likedMoviesAction, SIGNAL(triggered()), this, SLOT());
    
    QAction* historyAction = profileMenu->addAction("History");
    //connect(historyAction, SIGNAL(triggered()), this, SLOT());
    
    QAction* signOutAction = profileMenu->addAction("Sign Out");
    connect(signOutAction, SIGNAL(triggered()), this, SLOT(logInPage()));
}
void QTInterface::homePage()
{
    ui.stackedWidget->setCurrentIndex(2);
}
void QTInterface::moviesPage()
{
    ui.stackedWidget->setCurrentIndex(3);
}
void QTInterface::showsPage()
{
    ui.stackedWidget->setCurrentIndex(4);
}
void QTInterface::watchlistPage()
{
    //ui.stackedWidget->setCurrentIndex();
}
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
void QTInterface::logInPage() {
    ui.stackedWidget->setCurrentIndex(0);
    ui.menuBar->hide();
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
void QTInterface::accountPage() {
    ui.stackedWidget->setCurrentIndex(6);
}