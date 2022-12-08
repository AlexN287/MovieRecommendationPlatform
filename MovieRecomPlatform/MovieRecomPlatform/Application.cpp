#include "Application.h"
#include "Database.h"
#include"Movies.h"
#include <algorithm>
#include<iostream>
#include<math.h>
#include<string>

int min(int x, int y, int z) { return std::min(std::min(x, y), z); }

int editDist(std::string str1, std::string str2, int m, int n)
{
    // Create a table to store results of subproblems
    int** dp = new int*[m+1];

    for (int i = 0; i < m+1; i++) {
        dp[i] = new int[n+1];
    }

    // Fill d[][] in bottom up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            // If first string is empty, only option is to
            // insert all characters of second string
            if (i == 0)
                dp[i][j] = j; // Min. operations = j

            // If second string is empty, only option is to
            // remove all characters of second string
            else if (j == 0)
                dp[i][j] = i; // Min. operations = i

            // If last characters are same, ignore last char
            // and recur for remaining string
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            // If the last character is different, consider
            // all possibilities and find the minimum
            else
                dp[i][j]
                = 1
                + min(dp[i][j - 1], // Insert
                    dp[i - 1][j], // Remove
                    dp[i - 1][j - 1]); // Replace
        }
    }

    return dp[m][n];
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
        }));
}

void Application::SearchMovie(std::string movieName)
{
    auto moviesList = Database::GetInstance()->GetElements<Movies>();
    std::vector<Movies> foundMovies;

    toLower(movieName);
    removeSpaces(movieName);

    for (int i = 0; i < moviesList.size(); i++)
    {
        std::string title = moviesList[i].GetTitle();;
        toLower(title);
        removeSpaces(title);
       
        if(findSubString(title,movieName))
            foundMovies.push_back(moviesList[i]);
    }

    if (foundMovies.size()<=1)
    {
        for (int i = 0; i < moviesList.size(); i++)
        {
            std::string title = moviesList[i].GetTitle();
            toLower(title);
            removeSpaces(title);

            if (editDist(title, movieName, title.size(), movieName.size()) < 2)
                foundMovies.push_back(moviesList[i]);
        }
    }
    for (int i = 0; i < foundMovies.size(); i++)
        std::cout << foundMovies[i].GetTitle() << '\n';
   // return foundMovies;
}

bool Application::findSubString(std::string string, const std::string& subString)
{
    auto it = std::search(
        string.begin(), string.end(),
        subString.begin(), subString.end()
    );
    return (it==string.begin());
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
