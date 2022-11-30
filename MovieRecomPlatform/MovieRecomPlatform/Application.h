#pragma once
#include"Movies.h"

class Application
{
	enum class SearchStatus
	{
		Found,
		NotFound
	};

public:
	Application() = default;
	Movies SearchMovie(const std::string& movieName);
	bool findSubString(const std::string& string, const std::string& subString);
	void ShowMovie();
};

