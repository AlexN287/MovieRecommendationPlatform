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

public:
	Application();
	static std::vector<Movies> SearchMovie(std::string movieName);
	void AddToWishList(const User& user, const Movies& movie);
	void AddToWatchedList(const User& user, const Movies& movie);
	void GiveRating(const User& user,const Movies& movie, int rating);
	void RemoveFromWishlist(const User& user, const Movies& movie);
	void RemoveFromWatchedlist(const User& user, const Movies& movie);
	void RemoveRating(const User& user, const Movies& movie);
	void SelectRandomMovies(std::vector<Movies>& randomMoviesList, int number);
	Movies SelectMovie();
	void RecommendInitialMovies(const User& user);
	void RecommendMoviesBasedOnInput(const Movies& movie, const User& user);
	void DeleteLeastRecentRecommendedMovie(const User& user);
	std::vector<Movies> SelectRandomMoviesFromRecommandation(const User& user);
	
};

