#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QTInterface.h"

class QTInterface : public QMainWindow
{
    Q_OBJECT

public:
    QTInterface(QWidget* parent = nullptr);
    ~QTInterface();

private slots:
    void on_pushButton_login_clicked();
    void on_pushButton_signUp_clicked();
    void on_checkBox_male_stateChanged(int arg);
    void on_checkBox_female_stateChanged(int arg);
    void on_checkBox_like_stateChanged(int arg);
    void on_checkBox_dislike_stateChanged(int arg);
    void on_pushButton_back_clicked();
    void on_pushButton_change_username_clicked();
    void on_pushButton_change_password_clicked();
    void on_pushButton_delete_account_clicked();
    void on_pushButton_continue_clicked();
    void on_pushButton_signUp_done_clicked();
    void on_pushButton_remove_watchlist_clicked();
    void on_pushButton_movie_page_clicked();
    void on_pushButton_moviePage_history_clicked();
    void on_pushButton_liked_remove_clicked();
    void on_pushButton_liked_moviePage_clicked();
    void createMenuBar();
    void homePage();
    void watchlistPage();
    void logInPage();
    void accountPage();
    void historyPage();
    void likedPage();
private:
    Ui::QTInterfaceClass ui;
    //void populateGenreList();
    //void populateWatchlistList();
};

