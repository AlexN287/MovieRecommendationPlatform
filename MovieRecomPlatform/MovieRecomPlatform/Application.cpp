#include "Application.h"
#include<algorithm>

Movies Application::SearchMovie(const std::string& movieName)
{
    //return Movies();
}

bool Application::findSubString(std::optional<std::unique_ptr<std::string>> string, const std::string& subString)
{
    std::string s = *string->get();
    auto it = std::search(
        s.begin(), s.end(),
        subString.begin(), subString.end(),
        [](char ch1, char ch2) { return std::toupper(ch1) == std::toupper(ch2); }
    );
    return (it==s.begin());
}
