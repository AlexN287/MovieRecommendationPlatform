#pragma once

#include <QtWidgets/QMainWindow>
#include "User.h"
#include "Movies.h"
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
    void writeMovieToFile(const Movies& movie, std::string filename);
    void accountPage();
    void historyPage();
    void moviePage(const Movies& movie);
    void likedPage();
    void populateGenreList();
    void on_checkBox_watchlist_stateChanged(int arg);
    void on_checkBox_watched_stateChanged(int arg);
    void on_pushButton_forYou_1_clicked();
    void on_pushButton_forYou_2_clicked();
    void on_pushButton_forYou_3_clicked();
    void on_pushButton_forYou_4_clicked();
    void on_pushButton_forYou_5_clicked();
    void on_pushButton_forYou_6_clicked();
    void on_pushButton_search_1_clicked();
    void on_pushButton_search_2_clicked();
    void on_pushButton_search_3_clicked();
    void on_pushButton_search_4_clicked();
    void on_pushButton_search_5_clicked();
    void on_pushButton_search_6_clicked();
    void on_pushButton_search_7_clicked();
    void on_pushButton_search_8_clicked();
    void on_pushButton_search_9_clicked();
    void on_pushButton_search_10_clicked();
    void on_pushButton_search_11_clicked();
    void on_pushButton_search_12_clicked();
    void searchFinding();
    void changeLabels();

private:
    Ui::QTInterfaceClass ui;
    User currentUser;
    Movies currentMovieOnPage;
    //void populateGenreList();
    //void populateWatchlistList();
};

