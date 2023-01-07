#pragma once
#include <optional>
#include <memory>
#include <iostream>
#include "Database.h"
#include "Movies.h"
#include "User.h"
#include "Login.h"
#include "SignUp.h"
#include "LikedGenre.h"

class Application
{
	enum class SearchStatus
	{
		Found,
		NotFound
	};

public:
	Application();
	void SearchMovie(std::string movieName);
	void ShowMovie(std::string movieName); //TODO
	void AddToWishList(const User& user, const Movies& movie);
	void AddToWatchedList(const User& user, const Movies& movie);
	void GiveRating(const User& user,const Movies& movie);
	Movies SelectMovie();
	void RecommendInitialMovies(const User& user);
	void RecommendMoviesBasedOnInput(const Movies& movie, const User& user);
	void DeleteLeastRecentRecommendedMovie(const User& user);

private:
	std::string SearchStatusToString(Application::SearchStatus searchStatus);
};

