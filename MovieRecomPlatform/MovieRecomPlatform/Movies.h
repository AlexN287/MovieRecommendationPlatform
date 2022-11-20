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
	std::string m_country;
	uint8_t m_rating;
	int m_duration;

public:
	Movies(int moviesId, std::string type, std::string title, std::string director, int releaseYear,
		 std::string country, uint8_t rating, int duration);
	Movies(const Movies& movies) = default;
	~Movies() = default;

	int GetMoviesID() const;
	void SetMoviesID(int moviesId);
	std::string GetType() const;
	void SetType(std::string type);
	std::string GetTitle() const;
	void SetTitle(std::string title);
	std::string GetDirector() const;
	void SetDirector(std::string director);
	int GetReleaseYear() const;
	void SetReleaseYear(int releaseYear);
	std::string GetCountry() const;
	void SetCountry(std::string country);
	uint8_t GetRating() const;
	void SetRating(uint8_t rating);
	int GetDuration() const;
	void SetDuration(int duration);
};

