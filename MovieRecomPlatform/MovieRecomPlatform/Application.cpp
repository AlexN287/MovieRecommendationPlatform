#include "Application.h"
#include<algorithm>


Movies Application::SearchMovie(const std::string& movieName)
{
    using namespace sqlite_orm;
    namespace sql = sqlite_orm;
    Database db;

    auto foundMovies = db.m_storage.select(columns(&Movies::GetTitle, &Movies::GetType, &Movies::GetDirector, &Movies::GetReleaseYear,
        &Movies::GetCountry, &Movies::GetRating, &Movies::GetDuration),
        sql::where (c(&Movies::GetTitle) == movieName));

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

std::string Application::SearchStatusToString(Application::SearchStatus searchStatus)
{
    switch (searchStatus)
    {
    case Application::SearchStatus::Found :
        return "Found";
        break;
    case Application::SearchStatus::NotFound: 
        return "Not found";
        break;
    default:
        return "Error";
        break;
    }
}
