#include "Application.h"
#include<algorithm>

Movies Application::SearchMovie(const std::string& movieName)
{
    //return Movies();
}

bool Application::findSubString(const std::string& string, const std::string& subString)
{
    auto it = std::search(
        string.begin(), string.end(),
        subString.begin(), subString.end(),
        [](char ch1, char ch2) { return std::toupper(ch1) == std::toupper(ch2); }
    );
    return (it==string.begin());
}
