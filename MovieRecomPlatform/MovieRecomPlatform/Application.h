#pragma once
#include <optional>
#include <memory>
#include <iostream>
#include "Database.h"
#include "Movies.h"
#include "User.h"

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
	void ShowMovie(std::string movieName); //TODO
	void AddToWishList(User user, Movies movie);
	void AddToWatchedList(User user, std::string moveName);
	void GiveRating(User user, std::string movieName);

private:
	std::string SearchStatusToString(Application::SearchStatus searchStatus);
};

