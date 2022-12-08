#include "Application.h"
#include "Database.h"
#include"Movies.h"
#include <algorithm>
#include<iostream>
#include<math.h>
#include<string>

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
        }));
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
