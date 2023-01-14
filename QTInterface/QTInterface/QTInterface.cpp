#include "QTInterface.h"
#include "QMessageBox"
#include "Login.h"
#include "SignUp.h"
#include <qsignalmapper.h>
#include "qfile.h"
#include <fstream>

QTInterface::QTInterface(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    createMenuBar();
    populateGenreList();
    //auto movies = Database::GetInstance()->GetElements<Movies>();
    //moviePage(movies[2]);
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

    ui.label_name->setText(QString::fromStdString(currentUser.GetUsername()));
}
void QTInterface::logInPage() {
    ui.stackedWidget->setCurrentIndex(0);
    ui.menuBar->hide();
}
void QTInterface::watchlistPage()
{
    auto watchlist = Database::GetInstance()->SelectUserWishList(currentUser.GetUserId());

    for (int i = 0; i < watchlist.size(); i++)
    {
        Movies currentMovie = Database::GetInstance()->SelectMovieById(*watchlist[i].GetMoviesID());
        QString movieName = QString::fromStdString(currentMovie.GetTitle());
        QListWidgetItem* item = new QListWidgetItem(movieName);
        ui.listWidget_watchlist->addItem(item);
    }

    ui.listWidget_watchlist->clearSelection();
    ui.stackedWidget->setCurrentIndex(6);
}
void QTInterface::writeMovieToFile(const Movies& movie, std::string filename)
{
    std::ofstream fout(filename);

    fout << "Description: " << movie.GetDescription() << "\n\n";
    fout << "Director: " << movie.GetDirector() << "\n\n";
    fout << "Cast: " << movie.GetCast() << "\n\n";
    fout << "Genres: " << movie.GetGenres() << "\n\n";
    fout << "Type: " << movie.GetType() << "\n\n";
    fout << "Country: " << movie.GetCountry() << "\n\n";
    fout << "Release year: " << movie.GetReleaseYear() << "\n\n";
    fout << "Rating: " << movie.GetRating() << "\n\n";
    fout << "Duration: " << movie.GetDuration() << "\n\n";

    fout.close();
 
}

void QTInterface::moviePage(const Movies& movie)
{
    
    ui.stackedWidget->setCurrentIndex(3);
    ui.label->setText(QString::fromStdString(movie.GetTitle()));

    writeMovieToFile(movie, "movie.txt");

    QFile file("movie.txt");

    file.open(QFile::ReadOnly | QFile::Text);

    ui.plainTextEdit->setPlainText(file.readAll());

    auto watchList = Database::GetInstance()->SelectUserWishList(currentUser.GetUserId());
    auto history = Database::GetInstance()->SelectUserWatchedList(currentUser.GetUserId());
    auto userRating = Database::GetInstance()->SelectUserRating(currentUser.GetUserId());

    for (int i = 0; i < watchList.size(); i++)
    {
        if (movie.GetMoviesID() == *watchList[i].GetMoviesID())
        {
            ui.checkBox_watchlist->setChecked(1);
            break;
        }
    }

    for (int i = 0; i < history.size(); i++)
    {
        if (movie.GetMoviesID() == *history[i].GetMoviesID())
        {
            ui.checkBox_watched->setChecked(1);
            break;
        }
    }

    for (int i = 0; i < userRating.size(); i++)
    {
        if (movie.GetMoviesID() == *userRating[i].GetMovieId())
        {
            if(userRating[i].GetRating() == 1)
                ui.checkBox_like->setChecked(1);
            else
                ui.checkBox_dislike->setChecked(1);
            break;
        }
    }

}


void QTInterface::historyPage() {

    auto history = Database::GetInstance()->SelectUserWatchedList(currentUser.GetUserId());

    for (int i = 0; i < history.size(); i++)
    {
        Movies currentMovie = Database::GetInstance()->SelectMovieById(*history[i].GetMoviesID());
        QString movieName = QString::fromStdString(currentMovie.GetTitle());
        QListWidgetItem* item = new QListWidgetItem(movieName);
        ui.listWidget_watchlist->addItem(item);
    } 
    ui.listWidget_history->clearSelection();
    ui.stackedWidget->setCurrentIndex(7);
}
void QTInterface::likedPage() {

    auto userRating = Database::GetInstance()->SelectUserRating(currentUser.GetUserId());
    std::vector<UserRating> likedMovies;

    for (int i = 0; i < userRating.size(); i++)
        if (userRating[i].GetRating() == 1)
            likedMovies.push_back(userRating[i]);

    for (int i = 0; i < likedMovies.size(); i++)
    {
        Movies currentMovie = Database::GetInstance()->SelectMovieById(*likedMovies[i].GetMovieId());
        QString movieName = QString::fromStdString(currentMovie.GetTitle());
        QListWidgetItem* item = new QListWidgetItem(movieName);
        ui.listWidget_watchlist->addItem(item);
    } 

    ui.listWidget_history->clearSelection();
    ui.stackedWidget->setCurrentIndex(8);
}
void QTInterface::on_pushButton_login_clicked()
{
    std::string username = ui.lineEdit_username->text().toStdString();
    std::string password = ui.lineEdit_password->text().toStdString();

    Login login(username, password);
    User user = login.getUser();

    if (login.checkUser(user))
    {
        currentUser = user;
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
    if (SignUp::existentUsername(username))
    {
        ui.lineEdit_username_account->clear();
        QMessageBox::warning(this, "Error", "Username already exists!");
    }
    else if (SignUp::hasSpecialCharacters(username))
    {
        ui.lineEdit_username_account->clear();
        QMessageBox::warning(this, "Error", "Username contains special characters!");
    }
    else
    Login::updateUserUsername(currentUser, username);
    ui.lineEdit_username_account->clear();
    ui.label_name->setText(QString::fromStdString(currentUser.GetUsername()));
}
void QTInterface::on_pushButton_change_password_clicked() {
    std::string password = ui.lineEdit_password_account->text().toStdString();
 
    Login::updateUserPassword(currentUser, password);
    ui.lineEdit_password_account->clear();
}
void QTInterface::on_pushButton_delete_account_clicked() {
    
    Login::deleteUser(currentUser);
    ui.stackedWidget->setCurrentIndex(0);
}

void QTInterface::populateGenreList()
{
    auto genres = Database::GetInstance()->GetElements<Genres>();

    for (int i = 0; i < genres.size(); i++)
    {
        QString currentGenre = QString::fromStdString(genres[i].GetName());
        QListWidgetItem* item = new QListWidgetItem(currentGenre);
        ui.listWidget_genres->addItem(item);
    }
}
void QTInterface::on_pushButton_continue_clicked() {

    if (ui.listWidget_genres->selectedItems().count() != 0)
    {
        std::vector<std::string> genres;

        for (auto it : ui.listWidget_genres->selectedItems())
        {
            genres.push_back(it->text().toStdString());
        }

        SignUp::newUserPreferences(currentUser, genres);

        ui.stackedWidget->setCurrentIndex(2);
        ui.listWidget_genres->clearSelection();
        ui.menuBar->show();
    }
    else
        QMessageBox::warning(this, "Error", "Please select at least one genre.");
}
void QTInterface::on_pushButton_signUp_done_clicked() {

    std::string username = ui.lineEdit_username_signup->text().toStdString();
    std::string password = ui.lineEdit_password_signup->text().toStdString();

    if (SignUp::hasSpecialCharacters(username))
    {
  
        ui.lineEdit_username_signup->clear();
        ui.lineEdit_password_signup->clear();
        QMessageBox::warning(this, "Error", "Username cannot contain special characters!");

    }

    else if (SignUp::existentUsername(username))
    {
        ui.lineEdit_username_signup->clear();
        ui.lineEdit_password_signup->clear();
        QMessageBox::warning(this, "Error", "Username already exists!");
    }
       
 
    else if (username != "" && password != "")
    {
        std::string birthdate = ui.comboBox_day->currentText().toStdString() + "." +
            ui.comboBox_month->currentText().toStdString() + "." + ui.comboBox_year->currentText().toStdString();
        std::string gender;
        if (ui.checkBox_female->isChecked())
        {
            gender = "female";
        }
        else
            gender = "male";

        SignUp signUp(username, password, birthdate, gender);

        currentUser = signUp.getCurrentUser();

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