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
	int m_releaseYear;
	std::string m_cast;
	std::string m_country;
	uint8_t m_rating;
	int m_duration;

public:
	Movies(int moviesId, std::string type, std::string title, std::string director, int releaseYear,
		std::string cast, std::string country, uint8_t rating, int duration);
	Movies(const Movies& movies) = default;
	~Movies() = default;

	int GetMoviesID() const;
	std::string GetType() const;
	std::string GetTitle() const;
	std::string GetDirector() const;
	int GetReleaseYear() const;
	std::string GetCast() const;
	std::string GetCountry() const;
	uint8_t GetRating() const;
	int GetDuration() const;
};

