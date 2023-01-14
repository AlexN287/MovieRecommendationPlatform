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
    
    QAction* watchlistAction = ui.menuBar->addAction("Watchlist");
    connect(watchlistAction, SIGNAL(triggered()), this, SLOT(watchlistPage()));

    QMenu* profileMenu = ui.menuBar->addMenu("Profile");
    QAction* accountAction = profileMenu->addAction("Account");
    connect(accountAction, SIGNAL(triggered()), this, SLOT(accountPage()));

    QAction* likedMoviesAction = profileMenu->addAction("Liked Movies");
    connect(likedMoviesAction, SIGNAL(triggered()), this, SLOT(likedPage()));
    
    QAction* historyAction = profileMenu->addAction("History");
    connect(historyAction, SIGNAL(triggered()), this, SLOT(historyPage()));
    
    QAction* signOutAction = profileMenu->addAction("Sign Out");
    connect(signOutAction, SIGNAL(triggered()), this, SLOT(logInPage()));
}
void QTInterface::homePage()
{
    ui.stackedWidget->setCurrentIndex(2);
}
void QTInterface::accountPage() {
    ui.stackedWidget->setCurrentIndex(4);
}
void QTInterface::logInPage() {
    ui.stackedWidget->setCurrentIndex(0);
    ui.menuBar->hide();
}
void QTInterface::watchlistPage()
{
    ui.listWidget_watchlist->clearSelection();
    ui.stackedWidget->setCurrentIndex(6);
}
void QTInterface::historyPage() {
    ui.listWidget_history->clearSelection();
    ui.stackedWidget->setCurrentIndex(7);
}
void QTInterface::likedPage() {
    ui.listWidget_history->clearSelection();
    ui.stackedWidget->setCurrentIndex(8);
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
void QTInterface::on_checkBox_like_stateChanged(int arg) {
    if (arg != 0)
        ui.checkBox_dislike->setChecked(0);
}
void QTInterface::on_checkBox_dislike_stateChanged(int arg) {
    if (arg != 0)
        ui.checkBox_like->setChecked(0);
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
void QTInterface::on_pushButton_continue_clicked() {
    if (ui.listWidget_genres->selectedItems().count() != 0)
    {
        ui.stackedWidget->setCurrentIndex(2);
        ui.listWidget_genres->clearSelection();
        ui.menuBar->show();
    }
    else
        QMessageBox::warning(this, "Error", "Please select at least one genre.");
}
void QTInterface::on_pushButton_signUp_done_clicked() {
    if (ui.lineEdit_username_signup->text() != "" && ui.lineEdit_password_signup->text() != "")
    {
        ui.stackedWidget->setCurrentIndex(5);
        ui.lineEdit_username_signup->clear();
        ui.lineEdit_password_signup->clear();
        ui.comboBox_day->setCurrentIndex(0);
        ui.comboBox_month->setCurrentIndex(0);
        ui.comboBox_year->setCurrentIndex(0);
        ui.checkBox_female->setChecked(0);
        ui.checkBox_male->setChecked(0);
    }
    else
        QMessageBox::warning(this, "Error", "No fields can be empty!");
}
void QTInterface::on_pushButton_remove_watchlist_clicked() {
    QList<QListWidgetItem*> items = ui.listWidget_watchlist->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        delete ui.listWidget_watchlist->takeItem(ui.listWidget_watchlist->row(item));
    }
}
void QTInterface::on_pushButton_movie_page_clicked() {
    if(ui.listWidget_watchlist->selectedItems().count()==1)
        ui.stackedWidget->setCurrentIndex(3);
    //create the movie page custom for item selected
} 
void QTInterface::on_pushButton_moviePage_history_clicked() {
    if (ui.listWidget_history->selectedItems().count() == 1)
        ui.stackedWidget->setCurrentIndex(3);
    //create the movie page custom for item selected
}
void QTInterface::on_pushButton_liked_remove_clicked() {
    QList<QListWidgetItem*> items = ui.listWidget_liked->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        delete ui.listWidget_liked->takeItem(ui.listWidget_liked->row(item));
    }
}
void QTInterface::on_pushButton_liked_moviePage_clicked() {
    if (ui.listWidget_liked->selectedItems().count() == 1)
        ui.stackedWidget->setCurrentIndex(3);
    //create the movie page custom for item selected
}