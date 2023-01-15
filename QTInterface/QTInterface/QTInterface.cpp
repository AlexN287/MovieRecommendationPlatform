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
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
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
    Application a;
    ui.stackedWidget->setCurrentIndex(2);

    std::vector<Movies> recommended = a.SelectRandomMoviesFromRecommandation(currentUser);
    std::vector<Movies> randomMovies; 
    a.SelectRandomMovies(randomMovies, 12);

    changeLabels();

    ui.pushButton_search_1->show();
    ui.pushButton_search_2->show();
    ui.pushButton_search_3->show();
    ui.pushButton_search_4->show();
    ui.pushButton_search_5->show();
    ui.pushButton_search_6->show();
    ui.pushButton_search_7->show();
    ui.pushButton_search_8->show();
    ui.pushButton_search_9->show();
    ui.pushButton_search_10->show();
    ui.pushButton_search_11->show();
    ui.pushButton_search_12->show();

    ui.label_forYou_1->setText(QString::fromStdString(recommended[0].GetTitle()));
    ui.label_forYou_2->setText(QString::fromStdString(recommended[1].GetTitle()));
    ui.label_forYou_3->setText(QString::fromStdString(recommended[2].GetTitle()));
    ui.label_forYou_4->setText(QString::fromStdString(recommended[3].GetTitle()));
    ui.label_forYou_5->setText(QString::fromStdString(recommended[4].GetTitle()));
    ui.label_forYou_6->setText(QString::fromStdString(recommended[5].GetTitle()));

    ui.label_search_1->setText(QString::fromStdString(randomMovies[0].GetTitle()));
    ui.label_search_2->setText(QString::fromStdString(randomMovies[1].GetTitle()));
    ui.label_search_3->setText(QString::fromStdString(randomMovies[2].GetTitle()));
    ui.label_search_4->setText(QString::fromStdString(randomMovies[3].GetTitle()));
    ui.label_search_5->setText(QString::fromStdString(randomMovies[4].GetTitle()));
    ui.label_search_6->setText(QString::fromStdString(randomMovies[5].GetTitle()));
    ui.label_search_7->setText(QString::fromStdString(randomMovies[6].GetTitle()));
    ui.label_search_8->setText(QString::fromStdString(randomMovies[7].GetTitle()));
    ui.label_search_9->setText(QString::fromStdString(randomMovies[8].GetTitle()));
    ui.label_search_10->setText(QString::fromStdString(randomMovies[9].GetTitle()));
    ui.label_search_11->setText(QString::fromStdString(randomMovies[10].GetTitle()));
    ui.label_search_12->setText(QString::fromStdString(randomMovies[11].GetTitle()));


    connect(ui.lineEdit, SIGNAL(returnPressed()), this, SLOT(searchFinding()));
    currentMovieOnPage.SetMoviesID(-1);

    
}
void QTInterface::changeLabels()
{
    ui.label_forYou_1->setParent(ui.pushButton_forYou_1);
    ui.label_forYou_2->setParent(ui.pushButton_forYou_2);
    ui.label_forYou_3->setParent(ui.pushButton_forYou_3);
    ui.label_forYou_4->setParent(ui.pushButton_forYou_4);
    ui.label_forYou_5->setParent(ui.pushButton_forYou_5);
    ui.label_forYou_6->setParent(ui.pushButton_forYou_6);

    ui.label_forYou_1->show();
    ui.label_forYou_2->show();
    ui.label_forYou_3->show();
    ui.label_forYou_4->show();
    ui.label_forYou_5->show();
    ui.label_forYou_6->show();

    ui.label_forYou_1->move(0, 0);
    ui.label_forYou_2->move(0, 0);
    ui.label_forYou_3->move(0, 0);
    ui.label_forYou_4->move(0, 0);
    ui.label_forYou_5->move(0, 0);
    ui.label_forYou_6->move(0, 0);

    ui.label_search_1->setParent(ui.pushButton_search_1);
    ui.label_search_2->setParent(ui.pushButton_search_2);
    ui.label_search_3->setParent(ui.pushButton_search_3);
    ui.label_search_4->setParent(ui.pushButton_search_4);
    ui.label_search_5->setParent(ui.pushButton_search_5);
    ui.label_search_6->setParent(ui.pushButton_search_6);
    ui.label_search_7->setParent(ui.pushButton_search_7);
    ui.label_search_8->setParent(ui.pushButton_search_8);
    ui.label_search_9->setParent(ui.pushButton_search_9);
    ui.label_search_10->setParent(ui.pushButton_search_10);
    ui.label_search_11->setParent(ui.pushButton_search_11);
    ui.label_search_12->setParent(ui.pushButton_search_12);

    ui.label_search_1->show();
    ui.label_search_2->show();
    ui.label_search_3->show();
    ui.label_search_4->show();
    ui.label_search_5->show();
    ui.label_search_6->show();
    ui.label_search_7->show();
    ui.label_search_8->show();
    ui.label_search_9->show();
    ui.label_search_10->show();
    ui.label_search_11->show();
    ui.label_search_12->show();

    ui.label_search_1->move(0, 0);
    ui.label_search_2->move(0, 0);
    ui.label_search_3->move(0, 0);
    ui.label_search_4->move(0, 0);
    ui.label_search_5->move(0, 0);
    ui.label_search_6->move(0, 0);
    ui.label_search_7->move(0, 0);
    ui.label_search_8->move(0, 0);
    ui.label_search_9->move(0, 0);
    ui.label_search_10->move(0, 0);
    ui.label_search_11->move(0, 0);
    ui.label_search_12->move(0, 0);


}
void QTInterface::searchFinding()
{
    if (ui.lineEdit->text() == "")
    {
        homePage();
    }
    else
    {
        Application a;
        std::string searchName = ui.lineEdit->text().toStdString();

        ui.pushButton_search_1->hide();
        ui.pushButton_search_2->hide();
        ui.pushButton_search_3->hide();
        ui.pushButton_search_4->hide();
        ui.pushButton_search_5->hide();
        ui.pushButton_search_6->hide();
        ui.pushButton_search_7->hide();
        ui.pushButton_search_8->hide();
        ui.pushButton_search_9->hide();
        ui.pushButton_search_10->hide();
        ui.pushButton_search_11->hide();
        ui.pushButton_search_12->hide();

        std::vector<Movies> foundMovies = a.SearchMovie(searchName);

        int moviesToDisplay = 12;

        QList<QPushButton*> buttonList = ui.groupBox_1->findChildren<QPushButton*>();
        QList<QLabel*> labelList = ui.groupBox_1->findChildren<QLabel*>();


        if (foundMovies.size() < moviesToDisplay)
            moviesToDisplay = foundMovies.size();

        for (int i = 0; i < moviesToDisplay; i++)
        {
            QPushButton* button = buttonList[i];
            button->show();

            labelList[i]->setText(QString::fromStdString(foundMovies[i].GetTitle()));

        }
    }

}
void QTInterface::accountPage() {
    ui.stackedWidget->setCurrentIndex(4);

    ui.label_name->setText(QString::fromStdString(currentUser.GetUsername()));
    currentMovieOnPage.SetMoviesID(-1);
}
void QTInterface::logInPage() {
    ui.stackedWidget->setCurrentIndex(0);
    ui.menuBar->hide();
    currentMovieOnPage.SetMoviesID(-1);
}
void QTInterface::watchlistPage()
{
    ui.listWidget_watchlist->clear();
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
    currentMovieOnPage.SetMoviesID(-1);
}
void QTInterface::writeMovieToFile(const Movies& movie, std::string filename)
{
    std::ofstream fout(filename);

    fout << "Description: ";
    if (movie.GetDescription() != "")
        fout << movie.GetDescription() << "\n\n";
    else fout << "Not available." << "\n\n";
    fout << "Director: ";
    if (movie.GetDirector() != "")
        fout << movie.GetDirector() << "\n\n";
    else fout << "Not available." << "\n\n";
    fout << "Cast: ";
    if (movie.GetCast() != "")
        fout << movie.GetCast() << "\n\n";
    else fout << "Not available." << "\n\n";
    fout << "Genres: ";
    if (movie.GetGenres() != "")
        fout << movie.GetGenres() << "\n\n";
    else fout << "Not available." << "\n\n";
    fout << "Type: ";
    if (movie.GetType() != "")
        fout << movie.GetType() << "\n\n";
    else fout << "Not available." << "\n\n";
    fout << "Country: ";
    if (movie.GetCountry() != "")
        fout << movie.GetCountry() << "\n\n";
    else fout << "Not available." << "\n\n";
    fout << "Release year: ";
    if (movie.GetReleaseYear() != "")
        fout << movie.GetReleaseYear() << "\n\n";
    else fout << "Not available." << "\n\n";
    fout << "Rating: ";
    if (movie.GetRating() != "")
        fout << movie.GetRating() << "\n\n";
    else fout << "Not available." << "\n\n";
    fout << "Duration: ";
    if (movie.GetDuration() != "")
        fout << movie.GetDuration() << "\n\n";
    else fout << "Not available." << "\n\n";

    fout.close();
 
}

void QTInterface::moviePage(const Movies& movie)
{
    ui.checkBox_watched->setChecked(0);
    ui.checkBox_watchlist->setChecked(0);
    ui.checkBox_like->setChecked(0);
    ui.checkBox_dislike->setChecked(0);

    currentMovieOnPage = movie;
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
            if (userRating[i].GetRating() == 1)
                ui.checkBox_like->setChecked(1);
            else
                ui.checkBox_dislike->setChecked(1);
            break;
        }
    }
}

void QTInterface::historyPage() {

    ui.listWidget_history->clear();
    auto history = Database::GetInstance()->SelectUserWatchedList(currentUser.GetUserId());

    for (int i = 0; i < history.size(); i++)
    {
        Movies currentMovie = Database::GetInstance()->SelectMovieById(*history[i].GetMoviesID());
        QString movieName = QString::fromStdString(currentMovie.GetTitle());
        QListWidgetItem* item = new QListWidgetItem(movieName);
        ui.listWidget_history->addItem(item);
    } 
    ui.listWidget_history->clearSelection();
    ui.stackedWidget->setCurrentIndex(7);
    currentMovieOnPage.SetMoviesID(-1);
}
void QTInterface::likedPage() {

    ui.listWidget_liked->clear();
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
        ui.listWidget_liked->addItem(item);
    } 

    ui.listWidget_history->clearSelection();
    ui.stackedWidget->setCurrentIndex(8);
    currentMovieOnPage.SetMoviesID(-1);
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
        homePage();
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
    Application a;
    if (arg != 0)
    {
        ui.checkBox_dislike->setChecked(0);

        
        int rating = 1;
        a.GiveRating(currentUser, currentMovieOnPage, rating);
    }
    else
    {
        if (ui.checkBox_dislike->checkState() == 0)
        {
            a.RemoveRating(currentUser, currentMovieOnPage);
        }
    }
         
}
void QTInterface::on_checkBox_dislike_stateChanged(int arg) {
    Application a;
    if (arg != 0)
    {
        ui.checkBox_like->setChecked(0);

        
        int rating = 0;
        a.GiveRating(currentUser, currentMovieOnPage, rating);
    }
    else
    {
        if (ui.checkBox_like->checkState() == 0)
        {
            a.RemoveRating(currentUser, currentMovieOnPage);
        }
    }
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
    currentUser.SetUserId(-1);
    ui.menuBar->hide();
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
void QTInterface::on_checkBox_watchlist_stateChanged(int arg)
{
    Application a;
    if (arg == 0)
    {
        a.RemoveFromWishlist(currentUser, currentMovieOnPage);
    }
    else
    {
        a.AddToWishList(currentUser, currentMovieOnPage);
    }
}
void QTInterface::on_checkBox_watched_stateChanged(int arg)
{
    Application a;
    if (arg == 0)
    {
        a.RemoveFromWatchedlist(currentUser, currentMovieOnPage);
    }
    else
    {
        a.AddToWatchedList(currentUser, currentMovieOnPage);
    }
    
}

void QTInterface::on_pushButton_forYou_1_clicked()
{
    std::string movieName = ui.label_forYou_1->text().toStdString();
    Movies movie = Database::GetInstance()->SelectMovieByName(movieName);
    moviePage(movie);
}
void QTInterface::on_pushButton_forYou_2_clicked()
{
    std::string movieName = ui.label_forYou_2->text().toStdString();
    Movies movie = Database::GetInstance()->SelectMovieByName(movieName);
    moviePage(movie);
}
void QTInterface::on_pushButton_forYou_3_clicked()
{
    std::string movieName = ui.label_forYou_3->text().toStdString();
    Movies movie = Database::GetInstance()->SelectMovieByName(movieName);
    moviePage(movie);
}
void QTInterface::on_pushButton_forYou_4_clicked()
{
    std::string movieName = ui.label_forYou_4->text().toStdString();
    Movies movie = Database::GetInstance()->SelectMovieByName(movieName);
    moviePage(movie);
}
void QTInterface::on_pushButton_forYou_5_clicked()
{
    std::string movieName = ui.label_forYou_5->text().toStdString();
    Movies movie = Database::GetInstance()->SelectMovieByName(movieName);
    moviePage(movie);
}
void QTInterface::on_pushButton_forYou_6_clicked()
{
    std::string movieName = ui.label_forYou_6->text().toStdString();
    Movies movie = Database::GetInstance()->SelectMovieByName(movieName);
    moviePage(movie);
}
void QTInterface::on_pushButton_continue_clicked() {

    Application a;
    if (ui.listWidget_genres->selectedItems().count() != 0)
    {
        std::vector<std::string> genres;

        for (auto it : ui.listWidget_genres->selectedItems())
        {
            genres.push_back(it->text().toStdString());
        }

        SignUp::newUserPreferences(currentUser, genres);

        a.RecommendInitialMovies(currentUser);

        homePage();
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
        Application a;

        std::string movieName = ui.listWidget_watchlist->selectedItems().at(0)->text().toStdString();

        Movies movie = Database::GetInstance()->SelectMovieByName(movieName);

        a.RemoveFromWishlist(currentUser, movie);

        delete ui.listWidget_watchlist->takeItem(ui.listWidget_watchlist->row(item));
    }
}
void QTInterface::on_pushButton_movie_page_clicked() {
    if (ui.listWidget_watchlist->selectedItems().count() == 1)
    {
        std::string movieName = ui.listWidget_watchlist->selectedItems().at(0)->text().toStdString();
        Movies movies = Database::GetInstance()->SelectMovieByName(movieName);
        moviePage(movies);
    }
} 
void QTInterface::on_pushButton_moviePage_history_clicked() {
    if (ui.listWidget_history->selectedItems().count() == 1)
    {

        std::string movieName = ui.listWidget_history->selectedItems().at(0)->text().toStdString();
        Movies movies = Database::GetInstance()->SelectMovieByName(movieName);
        moviePage(movies);

    }
        
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
    {
        std::string movieName = ui.listWidget_liked->selectedItems().at(0)->text().toStdString();
        Movies movies = Database::GetInstance()->SelectMovieByName(movieName);
        moviePage(movies);
    }
        
   
}
void QTInterface::on_pushButton_search_1_clicked() {
    std::string movieName = ui.label_search_1->text().toStdString();
    Movies movie = Database::GetInstance()->SelectMovieByName(movieName);
    moviePage(movie);
}
void QTInterface::on_pushButton_search_2_clicked() {
    std::string movieName = ui.label_search_2->text().toStdString();
    Movies movie = Database::GetInstance()->SelectMovieByName(movieName);
    moviePage(movie);
}
void QTInterface::on_pushButton_search_3_clicked() {
    std::string movieName = ui.label_search_3->text().toStdString();
    Movies movie = Database::GetInstance()->SelectMovieByName(movieName);
    moviePage(movie);
}
void QTInterface::on_pushButton_search_4_clicked() {
    std::string movieName = ui.label_search_4->text().toStdString();
    Movies movie = Database::GetInstance()->SelectMovieByName(movieName);
    moviePage(movie);
}
void QTInterface::on_pushButton_search_5_clicked() {
    std::string movieName = ui.label_search_5->text().toStdString();
    Movies movie = Database::GetInstance()->SelectMovieByName(movieName);
    moviePage(movie);
}
void QTInterface::on_pushButton_search_6_clicked() {
    std::string movieName = ui.label_search_6->text().toStdString();
    Movies movie = Database::GetInstance()->SelectMovieByName(movieName);
    moviePage(movie);
}
void QTInterface::on_pushButton_search_7_clicked() {
    std::string movieName = ui.label_search_7->text().toStdString();
    Movies movie = Database::GetInstance()->SelectMovieByName(movieName);
    moviePage(movie);
}
void QTInterface::on_pushButton_search_8_clicked() {
    std::string movieName = ui.label_search_8->text().toStdString();
    Movies movie = Database::GetInstance()->SelectMovieByName(movieName);
    moviePage(movie);
}
void QTInterface::on_pushButton_search_9_clicked() {
    std::string movieName = ui.label_search_9->text().toStdString();
    Movies movie = Database::GetInstance()->SelectMovieByName(movieName);
    moviePage(movie);
}
void QTInterface::on_pushButton_search_10_clicked() {
    std::string movieName = ui.label_search_10->text().toStdString();
    Movies movie = Database::GetInstance()->SelectMovieByName(movieName);
    moviePage(movie);
}
void QTInterface::on_pushButton_search_11_clicked() {
    std::string movieName = ui.label_search_11->text().toStdString();
    Movies movie = Database::GetInstance()->SelectMovieByName(movieName);
    moviePage(movie);
}
void QTInterface::on_pushButton_search_12_clicked() {
    std::string movieName = ui.label_search_12->text().toStdString();
    Movies movie = Database::GetInstance()->SelectMovieByName(movieName);
    moviePage(movie);
}