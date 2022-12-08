#pragma once
#include <optional>
#include <memory>
#include <iostream>

class Application
{
	enum class SearchStatus
	{
		Found,
		NotFound
	};

public:
	Application() = default;
	void SearchMovie(std::string movieName);
	bool findSubString(std::string string, const std::string& subString);
	void ShowMovie(std::string movieName); //TODO
	std::string SearchStatusToString(Application::SearchStatus searchStatus);
};

