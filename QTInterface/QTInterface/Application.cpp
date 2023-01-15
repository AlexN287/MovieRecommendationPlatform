#include "Application.h"
#include <algorithm>
#include<iostream>
#include<math.h>
#include<string>
#include <vector>
#include<random>

Application::Application()
{
}

Movies Application::SelectMovie()
{
    auto movies = Database::GetInstance()->GetElements<Movies>();
    return movies[0];
}

void Application::SelectRandomMovies(std::vector<Movies>& randomMoviesList, int number)
{
    const int moviesNumber = 8202;
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(1, moviesNumber);
  
    auto moviesList = Database::GetInstance()->GetElements<Movies>();

    int count = 1;
    
    while (count <= number)
    {
        int index = distr(eng);
        if (std::find(randomMoviesList.begin(), randomMoviesList.end(), moviesList[index]) == randomMoviesList.end())
        {
            randomMoviesList.push_back(moviesList[index]);
            count++;

        }
            
    }

}

std::vector<Movies> Application::SelectRandomMoviesFromRecommandation(const User& user)
{
    auto recommendedMovies = Database::GetInstance()->SelectUserRecommandation(user.GetUserId());
    std::vector<Movies> selectedMovies;
   
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(1, recommendedMovies.size() - 1);

    while (selectedMovies.size() < 6)
    {
        int index = distr(eng);
        Recommandation recommendation(recommendedMovies[index]);
        Movies currentMovie = Database::GetInstance()->SelectMovieById(*recommendation.GetMovieID());

        if (std::find(selectedMovies.begin(), selectedMovies.end(), currentMovie) == selectedMovies.end())
            selectedMovies.push_back(currentMovie);
    }

    return selectedMovies;
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

    const int moviesNumber = 8202;
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(1, moviesNumber);


    int count = 0;
    while (count <= 6) {

        int index = distr(eng);
        for (int j = 0; j < movieGenres.size() && count <= 10; j++)
        {
            if (moviesList[index].GetGenres().find(movieGenres[j]) != std::string::npos)
            {
                if (std::find(recommendMovies.begin(), recommendMovies.end(), moviesList[index]) == recommendMovies.end())
                {
                    recommendMovies.push_back(moviesList[index]);
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

    const int moviesNumber = 8202;
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(1, moviesNumber);

    int count = 0;
    while (count < 10) 
    {
        int index = distr(eng);
        for (int j = 0; j < genres.size() && count <= 10; j++)
        {
            if (moviesList[index].GetGenres().find(genres[j].GetName()) != std::string::npos)
            {
                if (std::find(recommendMovies.begin(), recommendMovies.end(), moviesList[index]) == recommendMovies.end())
                {
                    recommendMovies.push_back(moviesList[index]);
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
   
    FindMovieGenre(userGenres, recommendMovies);
    SelectRandomMovies(recommendMovies, 15);

    auto currentRecommandation = Database::GetInstance()->SelectUserRecommandation(user.GetUserId());
    std::vector<Movies> currentMovies;

    for (int i = 0; i < currentRecommandation.size(); i++)
    {
        Movies movie = Database::GetInstance()->SelectMovieById(*currentRecommandation[i].GetMovieID());
        currentMovies.push_back(movie);

    }

    std::vector<Movies> moviesToInsert;

    for (int i = 0; i < recommendMovies.size(); i++)
    {
        if (std::find(currentMovies.begin(), currentMovies.end(), recommendMovies[i]) == currentMovies.end())
            moviesToInsert.push_back(recommendMovies[i]);
    }

    for (int i = 0; i < moviesToInsert.size(); i++)
    {
        Movies currentMovie = moviesToInsert[i];
        std::unique_ptr<int> movieIdPtr = std::make_unique<int>(currentMovie.GetMoviesID());
        std::unique_ptr<int> userIdPtr = std::make_unique<int>(user.GetUserId());
        Database::GetInstance()->InsertElement(Recommandation(std::move(userIdPtr),
            std::move(movieIdPtr)));
    }
       
}

void Application::RecommendMoviesBasedOnInput(const Movies& movie, const User& user)
{
    int startIndex = 0;
    std::vector<Movies> recommendMovies;
    FindSimilarMovie(movie, recommendMovies);

    auto currentRecommandation = Database::GetInstance()->SelectUserRecommandation(user.GetUserId());
    std::vector<Movies> currentMovies;

    for (int i = 0; i < currentRecommandation.size(); i++)
    {
        Movies movie = Database::GetInstance()->SelectMovieById(*currentRecommandation[i].GetMovieID());
        currentMovies.push_back(movie);

    }

    std::vector<Movies> moviesToInsert;

    for (int i = 0; i < recommendMovies.size(); i++)
    {
        if (std::find(currentMovies.begin(), currentMovies.end(), recommendMovies[i]) == currentMovies.end())
            moviesToInsert.push_back(recommendMovies[i]);
    } 

    for (int i = 0; i < moviesToInsert.size(); i++)
    {
        Movies currentMovie = moviesToInsert[i];
        std::unique_ptr<int> movieIdPtr = std::make_unique<int>(currentMovie.GetMoviesID());
        std::unique_ptr<int> userIdPtr = std::make_unique<int>(user.GetUserId());
        Database::GetInstance()->InsertElement(Recommandation(std::move(userIdPtr),
            std::move(movieIdPtr)));
    }
}

void DeleteRecommendedMoviesByGenre(const std::vector<std::string>& genresToDelete, const User& user)
{
    auto recommendMovies = Database::GetInstance()->SelectUserRecommandation(user.GetUserId());
    int count = 0;
    for (int i = 0; i < recommendMovies.size(); i++)
    {
        std::string movieGenres = Database::GetInstance()->
            SelectMovieById(*recommendMovies[i].GetMovieID()).GetGenres();
        for (int j = 0; j < genresToDelete.size(); j++)
            if (movieGenres.find(genresToDelete[j]) != std::string::npos)
            {
                Database::GetInstance()->RemoveElement<Recommandation>(recommendMovies[i].GetRecommandationID());
                count++;
                break;
            }
        if (count == 3)
            break;
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
                Database::GetInstance()->RemoveElement<Recommandation>(recommendMovies[i].GetRecommandationID());
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

std::vector<Movies> Application::SearchMovie(std::string movieName)
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

            if (findSubString(title, foundMovie) && hasOnlyAlphaNum(moviesList[j].GetTitle()))
            {
                if (std::find(foundMovies.begin(), foundMovies.end(), moviesList[j]) == foundMovies.end())
                    foundMovies.push_back(moviesList[j]);
            }
                       
        }
           
    }
    
     return foundMovies;
}


void Application::AddToWishList(const User& user, const Movies& movie)
{
    auto userWishList = Database::GetInstance()->SelectUserWishList(user.GetUserId());
    int found = false;

    for (int i = 0; i < userWishList.size(); i++)
    {
        if (*userWishList[i].GetMoviesID() == movie.GetMoviesID())
        {
            found = true;
            break;
        }
    }

    if (found == false)
    {
        std::unique_ptr<int> userIdPtr = std::make_unique<int>(user.GetUserId());
        std::unique_ptr<int> movieIdPtr = std::make_unique<int>(movie.GetMoviesID());
        Database::GetInstance()->InsertElement(Wishlist(std::move(userIdPtr), std::move(movieIdPtr)));

        RecommendMoviesBasedOnInput(movie, user);
    }

}

void Application::AddToWatchedList(const User& user, const Movies& movie)
{
    auto userWatchedList = Database::GetInstance()->SelectUserWatchedList(user.GetUserId());
    int found = false;

    for (int i = 0; i < userWatchedList.size(); i++)
    {
        if (*userWatchedList[i].GetMoviesID() == movie.GetMoviesID())
        {
            found = true;
            break;
        }
    }

    if (found == false)
    {
        std::unique_ptr<int> userIdPtr = std::make_unique<int>(user.GetUserId());
        std::unique_ptr<int> movieIdPtr = std::make_unique<int>(movie.GetMoviesID());
        Database::GetInstance()->InsertElement(WatchedList(std::move(userIdPtr), std::move(movieIdPtr)));

        RecommendMoviesBasedOnInput(movie, user);
    }
}

void Application::GiveRating(const User& user, const Movies& movie, int rating)
{
    auto userRating = Database::GetInstance()->SelectUserRating(user.GetUserId());
    int found = false;
    UserRating currentRating;

    for (int i = 0; i < userRating.size(); i++)
    {
        if (*userRating[i].GetMovieId() == movie.GetMoviesID())
        {
            found = true;
            currentRating = userRating[i];
            break;
        }
    }

    if (found == false)
    {
        std::unique_ptr<int> userIdPtr = std::make_unique<int>(user.GetUserId());
        std::unique_ptr<int> movieIdPtr = std::make_unique<int>(movie.GetMoviesID());
        Database::GetInstance()->InsertElement(UserRating(std::move(userIdPtr), std::move(movieIdPtr), rating));

        if (rating == 1)
            RecommendMoviesBasedOnInput(movie, user);
        else
        {
            std::vector<std::string> movieGenres = splitChar(movie.GetGenres(), ",");
            DeleteRecommendedMoviesByGenre(movieGenres, user);
        }
    }
    else
    {
        currentRating.SetRating(rating);

        Database::GetInstance()->UpdateElement(currentRating);
    }
        
}

void Application::RemoveFromWishlist(const User& user, const Movies& movie)
{
    auto userWishlist = Database::GetInstance()->SelectUserWishList(user.GetUserId());

    for (int i = 0; i < userWishlist.size(); i++)
    {
        if (*userWishlist[i].GetMoviesID() == movie.GetMoviesID())
        {
            Database::GetInstance()->RemoveElement<Wishlist>(userWishlist[i].GetWishlistID());
            break;
        }
    }

    std::vector<std::string> movieGenres = splitChar(movie.GetGenres(), ",");
    DeleteRecommendedMoviesByGenre(movieGenres, user);
}

void Application::RemoveFromWatchedlist(const User& user, const Movies& movie)
{
    auto userWatchedlist = Database::GetInstance()->SelectUserWatchedList(user.GetUserId());

    for (int i = 0; i < userWatchedlist.size(); i++)
    {
        if (*userWatchedlist[i].GetMoviesID() == movie.GetMoviesID())
        {
            Database::GetInstance()->RemoveElement<Wishlist>(userWatchedlist[i].GetWatchedListId());
            break;
        }
    }
}

void Application::RemoveRating(const User& user, const Movies& movie)
{
    auto userRating = Database::GetInstance()->SelectUserRating(user.GetUserId());

    for (int i = 0; i < userRating.size(); i++)
    {
        if (*userRating[i].GetMovieId() == movie.GetMoviesID())
        {
            Database::GetInstance()->RemoveElement<Wishlist>(userRating[i].GetUserRatingId());
            break;
        }
    }
}
