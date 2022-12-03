#pragma once
#include<string>
#include<cstdint>

class Movies
{
private:
	int m_moviesId;
	std::string m_type;
	std::string m_title;
	std::string m_director;
	std::string m_cast;
	std::string m_country;
	std::string m_dateAdded;
	int m_releaseYear;
	std::string m_rating;
	int m_duration;
	std::string m_genres;
	std::string m_description;

public:
	Movies() = default;
	Movies(std::string type, std::string title, std::string director, std::string cast,
		 std::string country, std::string dateAdded, int releaseYear, std::string rating, int duration, 
		std::string genres, std::string description);
	Movies(const Movies& movies) = default;
	~Movies() = default;

	int GetMoviesID() const;
	void SetMoviesID(int moviesId);
	std::string GetType() const;
	void SetType( std::string type);
	std::string GetTitle() const;
	void SetTitle(std::string title);
	std::string GetDirector() const;
	void SetDirector(std::string director);
	std::string GetCast() const;
	void SetCast(std::string cast);
	int GetReleaseYear() const;
	void SetReleaseYear(int releaseYear);
	std::string GetCountry() const;
	void SetCountry(std::string country);
	std::string GetDateAdded() const;
	void SetDateAdded( std::string dateAdded);
	std::string GetRating() const;
	void SetRating(std::string rating);
	int GetDuration() const;
	void SetDuration(int duration);
	std::string GetGenres() const;
	void SetGenres(std::string genres);
	std::string GetDescription() const;
	void SetDescription(std::string description);
};

