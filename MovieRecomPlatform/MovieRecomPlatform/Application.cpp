#include "Application.h"
#include "Database.h"
#include"Movies.h"
#include <algorithm>

inline auto Application::SearchMovie(const std::string& movieName)
{
    using namespace sqlite_orm;
    namespace sql = sqlite_orm;
    Database db;

    auto foundMovies = db.m_storage.select(columns(&Movies::GetTitle, &Movies::GetType, &Movies::GetDirector, &Movies::GetReleaseYear,
        &Movies::GetCountry, &Movies::GetRating, &Movies::GetDuration),
        sql::where (c(&Movies::GetTitle) == movieName)); //TODO

    try {
        if (foundMovies.empty())
        {
            throw SearchStatusToString(Application::SearchStatus::NotFound);
        }
    }
    catch (const std::string& exception)
    {
        std::cout << exception;
    }


    return foundMovies;
 

}

bool Application::findSubString(std::string string, const std::string& subString)
{
    auto it = std::search(
        string.begin(), string.end(),
        subString.begin(), subString.end(),
        [](char ch1, char ch2) { return std::toupper(ch1) == std::toupper(ch2); }
    );
    return (it==string.begin());
}

void Application::ShowMovie(std::string movieName)
{
    using movies = decltype(SearchMovie(""));

    movies foundMovies = SearchMovie(movieName); //TODO

    int movieOption;
    if (!foundMovies.empty())
    {
        std::cout << "Select movie: \n";

        for (int i = 0; i < foundMovies.size(); i++)
        {
            std::cout << i + 1 << ". " << std::get<0>(foundMovies[i]) << " " << std::get<3>(foundMovies[i]) << "\n";
        }

        std::cout << "Enter: \n";
   
        std::cin >> movieOption;

        movieOption--;

        std::cout << "0 - Exit \n";
        std::cout << "1 - Show type \n";
        std::cout << "2 - Show director \n";
        std::cout << "3 - Show release year \n";
        std::cout << "4 - Show country \n";
        std::cout << "5 - Show rating \n";
        std::cout << "6 - Show duration \n";

        auto movie = foundMovies[movieOption];

        int option;
        std::cin >> option;

        while (option != 0) {

            switch (option)
            {

            case 1:
                std::cout << std::get<1>(movie) << "\n";
                break;
            case 2:
                std::cout << std::get<2>(movie) << "\n";
                break;
            case 3:
                std::cout << std::get<3>(movie) << "\n";
                break;
            case 4:
                std::cout << std::get<4>(movie) << "\n";
                break;
            case 5:
                std::cout << std::get<5>(movie) << "\n";
                break;
            case 6:
                std::cout << std::get<6>(movie) << "\n";
                break;
            }

            std::cin >> option;

        }


  
    }
}

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
