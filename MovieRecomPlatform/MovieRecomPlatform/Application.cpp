#include "Application.h"
#include <algorithm>
#include<iostream>
#include<math.h>
#include<string>
#include <vector>
#include<random>

Application::Application()
{
    std::string username, password;
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    bool exitCondition = false;
    Login login(username, password);
    User user = login.getUser();

    while (!login.checkUser(user))
    {
        std::cout << "Try again. \n";
        std::cout << "Username: ";
        std::cin >> username;
        std::cout << "Password: ";
        std::cin >> password;
        login = Login(username, password);
        user = login.getUser();
    }

    std::cout << "0 - Exit \n";
    std::cout << "1 - Show User \n";
    std::cout << "2 - Add movie to whishlist \n";
    std::cout << "3 - Add movie to watchedlist \n";
    std::cout << "4 - Give rating \n";

    int condition;
    while (!exitCondition)
    {
        std::cin >> condition;
        switch (condition)
        {
        case 0:
            exitCondition = true;
            break;

        case 1:
            login.showUser(user);
            break;

        case 2:
        {
            Movies movie = SelectMovie();
            AddToWishList(user, movie);
            break;
        }
        case 3:
        {
            Movies movie = SelectMovie();
            AddToWatchedList(user, movie);
            break;
        }
        case 4:
        {
            Movies movie = SelectMovie();
            GiveRating(user, movie);
            break;
        }

        }
    }
}

Movies Application::SelectMovie()
{
    auto movies = Database::GetInstance()->GetElements<Movies>();
    return movies[0];
}

void SelectRandomMovies(std::vector<Movies>& randomMoviesList)
{
    const int moviesNumber = 8202;
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(1, moviesNumber);
  
    auto moviesList = Database::GetInstance()->GetElements<Movies>();
    
    while (randomMoviesList.size() <= 10)
    {
        int index = distr(eng);
        if (std::find(randomMoviesList.begin(), randomMoviesList.end(), moviesList[index]) == randomMoviesList.end()) 
            randomMoviesList.push_back(moviesList[index]);
    }

}

std::vector<std::string> splitChar(const std::string& str, const std::string& delim)
{
    std::vector<std::string> result;
    size_t startIndex = 0;

    for (size_t found = str.find(delim); found != std::string::npos; found = str.find(delim, startIndex))
    {
        result.emplace_back(str.begin() + startIndex, str.begin() + found);
        startIndex = found + delim.size();
    }
    if (startIndex != str.size())
        result.emplace_back(str.begin() + startIndex, str.end());
    return result;
}

void FindSimilarMovie(const Movies& movie, std::vector<Movies>& recommendMovies)
{
    auto moviesList = Database::GetInstance()->GetElements<Movies>();
    const std::string delim = ",";
    std::vector<std::string> movieGenres = splitChar(movie.GetGenres(), delim);
    int count = 0;
    for (int i = 0; i < moviesList.size(); i++)
    {
        for (int j = 0; j < movieGenres.size() && count<=10; j++)
        {
            if (moviesList[i].GetGenres().find(movieGenres[j]))
            {
                if (std::find(recommendMovies.begin(), recommendMovies.end(), moviesList[i]) == recommendMovies.end())
                {
                    recommendMovies.push_back(moviesList[i]);
                    count++;
                    break;
                }
            }
        }
    }
}

void FindMovieGenre(const std::vector<Genres>& genres, std::vector<Movies>& recommendMovies)
{
    auto moviesList = Database::GetInstance()->GetElements<Movies>();
    int count = 0;
    for (int i = 0; i < moviesList.size(); i++)
    {
        for (int j = 0; j < genres.size() && count <= 20; j++)
        {
            if (moviesList[i].GetGenres().find(genres[j].GetName()))
            {
                if (std::find(recommendMovies.begin(), recommendMovies.end(), moviesList[i]) == recommendMovies.end())
                {
                    recommendMovies.push_back(moviesList[i]);
                    count++;
                    break;
                }
            }
        }
    }
}

std::vector<Genres> GetUserGenres(const User& user)
{
    auto userGenres = Database::GetInstance()->SelectUserLikedGenres(user.GetUserId());
    std::vector<Genres> genres;

    for (int i = 0; i < userGenres.size(); i++)
    {
        genres.push_back(userGenres[i].GetGenre());
    }

    return genres;

}

void Application::RecommendInitialMovies(const User& user)
{
    std::vector<Movies> recommendMovies;
    auto userGenres = GetUserGenres(user);
    std::unique_ptr<int> userIdPtr = std::make_unique<int>(user.GetUserId());
   
    FindMovieGenre(userGenres, recommendMovies);
    SelectRandomMovies(recommendMovies);

    for (int i = 0; i < recommendMovies.size(); i++)
    {
        Movies currentMovie = recommendMovies[i];
        std::unique_ptr<int> movieIdPtr = std::make_unique<int>(currentMovie.GetMoviesID());
        Database::GetInstance()->InsertElement(Recommandation(std::move(userIdPtr),
            std::move(movieIdPtr)));
    }
       
}

void Application::RecommendMoviesBasedOnInput(const Movies& movie, const User& user)
{
    std::vector<Movies> recommendMovies;
    FindSimilarMovie(movie, recommendMovies);
    std::unique_ptr<int> userIdPtr = std::make_unique<int>(user.GetUserId());
    for (int i = 0; i < recommendMovies.size(); i++)
    {
        Movies currentMovie = recommendMovies[i];
        std::unique_ptr<int> movieIdPtr = std::make_unique<int>(currentMovie.GetMoviesID());
        Database::GetInstance()->InsertElement(Recommandation(std::move(userIdPtr),
            std::move(movieIdPtr)));
    }
}

void DeleteRecommendedMoviesByGenre(const std::vector<std::string>& genresToDelete, const User& user)
{
    auto recommendMovies = Database::GetInstance()->SelectUserRecommandation(user.GetUserId());
    int countFiveMoviesToDelete = 0;
    for (int i = 0; i < recommendMovies.size() || countFiveMoviesToDelete == 5; i++)
    {
        std::string movieGenres = Database::GetInstance()->
            SelectMovieById(*recommendMovies[i].GetMovieID()).GetGenres();
        for(int j=0;j<genresToDelete.size();j++)
            if (movieGenres.find(genresToDelete[j]) != std::string::npos)
            {
                Database::GetInstance()->RemoveElement<Recommandation>(recommendMovies[i]);
                countFiveMoviesToDelete++;
            }
    }
}

void Application::DeleteLeastRecentRecommendedMovie(const User& user)
{
    auto recommendMovies = Database::GetInstance()->SelectUserRecommandation(user.GetUserId());
    const int firstThreeOldMovies = 3;
    std::vector<std::string> genresToDelete;
    for (int i = 0; i < firstThreeOldMovies; i++)
    {
        for (int j = recommendMovies.size() - 5; j < recommendMovies.size(); j++)
        {
            std::string oldMovieGenres = Database::GetInstance()->
                SelectMovieById(*recommendMovies[i].GetMovieID()).GetGenres();
            std::string recentMovieGenres = Database::GetInstance()->
                SelectMovieById(*recommendMovies[j].GetMovieID()).GetGenres();
            if (oldMovieGenres.compare(recentMovieGenres) != 0)
            {
                Database::GetInstance()->RemoveElement<Recommandation>(recommendMovies[i]);
                genresToDelete = splitChar(oldMovieGenres, ",");
            }
        }
    }
    DeleteRecommendedMoviesByGenre(genresToDelete, user);
}

int min(int x, int y, int z) { return std::min(std::min(x, y), z); }

int editDist(std::string str1, std::string str2, int str1Size, int str2Size)
{
    int** dp = new int*[str1Size+1];

    for (int i = 0; i < str1Size +1; i++) {
        dp[i] = new int[str2Size +1];
    }

    for (int i = 0; i <= str1Size; i++) {
        for (int j = 0; j <= str2Size; j++) {
            if (i == 0)
                dp[i][j] = j; 
            else if (j == 0)
                dp[i][j] = i; 
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            else
                dp[i][j]
                = 1
                + min(dp[i][j - 1], 
                    dp[i - 1][j], 
                    dp[i - 1][j - 1]); 
        }
    }

    return dp[str1Size][str2Size];
}

void toLower(std::string& str)
{
    std::transform(str.begin(), str.end(),
        str.begin(), ::tolower);
}

void removeSpaces(std::string& str)
{
    str.erase(std::remove_if(str.begin(), str.end(),
        [](char c) {
            return std::isspace(static_cast<unsigned char>(c));
        }), str.end());
}

void removeCharacters(std::string& str)
{
    str.erase(std::remove_if(str.begin(), str.end(), 
        [](char c) { return !isalnum(static_cast<unsigned char>(c)); }), str.end());
}

bool hasOnlyAlphaNum(const std::string& str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (static_cast<unsigned char>(str[i]) > 127)
            return false;
    }

    return true;
}

bool findSubString(std::string string, const std::string& subString)
{
    auto it = std::search(
        string.begin(), string.end(),
        subString.begin(), subString.end()
    );
    return (it == string.begin());
}

void Application::SearchMovie(std::string movieName)
{
    auto moviesList = Database::GetInstance()->GetElements<Movies>();
    std::vector<Movies> foundMovies;

    toLower(movieName);
    removeSpaces(movieName);
    removeCharacters(movieName);

    for (int i = 0; i < moviesList.size(); i++)
    {
        std::string title = moviesList[i].GetTitle();
        toLower(title);
        removeSpaces(title);
        removeCharacters(title);

        if (editDist(title, movieName, title.size(), movieName.size()) < 3)
        {
            if(hasOnlyAlphaNum(moviesList[i].GetTitle()))
                foundMovies.push_back(moviesList[i]);
        }
                
    }
    auto initial = foundMovies;
    if(!initial.empty())
        for (int i = 0; i < initial.size(); i++)
        {
            std::string foundMovie = initial[i].GetTitle();
            toLower(foundMovie);
            removeSpaces(foundMovie);
            removeCharacters(foundMovie);

            for (int j = 0; j < moviesList.size(); j++)
            { 
                std::string title = moviesList[j].GetTitle();
              
                toLower(title);
                removeSpaces(title);
                removeCharacters(title);

                if (findSubString(title, foundMovie))
                    if (hasOnlyAlphaNum(moviesList[j].GetTitle())) //TODO
                    { 
                      foundMovies.push_back(moviesList[j]);
                      //std::cout << moviesList[j].GetTitle() << "\n";
                    }
                       
            }
           
        }
    for (int i = 0; i < foundMovies.size(); i++)
        std::cout << foundMovies[i].GetTitle() << '\n';
    // return foundMovies;
}



//void Application::ShowMovie(std::string movieName)
//{
//    using movies = decltype(SearchMovie(""));
//
//    movies foundMovies = SearchMovie(movieName); //TODO
//
//    int movieOption;
//    if (!foundMovies.empty())
//    {
//        std::cout << "Select movie: \n";
//
//        for (int i = 0; i < foundMovies.size(); i++)
//        {
//            std::cout << i + 1 << ". " << std::get<0>(foundMovies[i]) << " " << std::get<3>(foundMovies[i]) << "\n";
//        }
//
//        std::cout << "Enter: \n";
//   
//        std::cin >> movieOption;
//
//        movieOption--;
//
//        std::cout << "0 - Exit \n";
//        std::cout << "1 - Show type \n";
//        std::cout << "2 - Show director \n";
//        std::cout << "3 - Show release year \n";
//        std::cout << "4 - Show country \n";
//        std::cout << "5 - Show rating \n";
//        std::cout << "6 - Show duration \n";
//
//        auto movie = foundMovies[movieOption];
//
//        int option;
//        std::cin >> option;
//
//        while (option != 0) {
//
//            switch (option)
//            {
//
//            case 1:
//                std::cout << std::get<1>(movie) << "\n";
//                break;
//            case 2:
//                std::cout << std::get<2>(movie) << "\n";
//                break;
//            case 3:
//                std::cout << std::get<3>(movie) << "\n";
//                break;
//            case 4:
//                std::cout << std::get<4>(movie) << "\n";
//                break;
//            case 5:
//                std::cout << std::get<5>(movie) << "\n";
//                break;
//            case 6:
//                std::cout << std::get<6>(movie) << "\n";
//                break;
//            }
//
//            std::cin >> option;
//
//        }
//
//
//  
//    }
//}

std::string Application::SearchStatusToString(Application::SearchStatus searchStatus)
{
    switch (searchStatus)
    {
    case Application::SearchStatus::Found :
        return "Found \n";
        break;
    case Application::SearchStatus::NotFound: 
        return "Not found \n";
        break;
    default:
        return "Error";
        break;
    }
}

void Application::AddToWishList(const User& user, const Movies& movie)
{
    std::unique_ptr<int> userIdPtr = std::make_unique<int>(user.GetUserId());
    std::unique_ptr<int> movieIdPtr = std::make_unique<int>(movie.GetMoviesID());
    Database::GetInstance()->InsertElement(Wishlist(std::move(userIdPtr), std::move(movieIdPtr)));

    RecommendMoviesBasedOnInput(movie, user);
}

void Application::AddToWatchedList(const User& user, const Movies& movie)
{
    std::unique_ptr<int> userIdPtr = std::make_unique<int>(user.GetUserId());
    std::unique_ptr<int> movieIdPtr = std::make_unique<int>(movie.GetMoviesID());
    Database::GetInstance()->InsertElement(WatchedList(std::move(userIdPtr), std::move(movieIdPtr)));

    RecommendMoviesBasedOnInput(movie, user);
}

void Application::GiveRating(const User& user, const Movies& movie)
{
    std::unique_ptr<int> userIdPtr = std::make_unique<int>(user.GetUserId());
    std::unique_ptr<int> movieIdPtr = std::make_unique<int>(movie.GetMoviesID());
    std::cout << "0/1" << "\n";
    int rating;
    std::cin >> rating;
    Database::GetInstance()->InsertElement(UserRating(std::move(userIdPtr), std::move(movieIdPtr), rating));

    if(rating == 1)
        RecommendMoviesBasedOnInput(movie, user);
    else
    {
        std::vector<std::string> movieGenres = splitChar(movie.GetGenres(), ",");
        DeleteRecommendedMoviesByGenre(movieGenres, user);
    }
        
}
