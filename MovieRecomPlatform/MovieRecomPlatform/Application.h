#pragma once
#include"Movies.h"
#include <optional>
#include <memory>
#include "Database.h"
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
	inline auto SearchMovie(const std::string& movieName);
	bool findSubString(std::string string, const std::string& subString);
	void ShowMovie();
	std::string SearchStatusToString(Application::SearchStatus searchStatus);
};
