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
	std::string m_country;
	std::string m_dateAdded;
	int m_releaseYear;
	uint8_t m_rating;
	int m_duration;
	std::string m_description;

public:
	Movies(std::string type, std::string title, std::string director,
		 std::string country, std::string dateAdded, int releaseYear, uint8_t rating, int duration, std::string description);
	Movies(const Movies& movies) = default;
	~Movies() = default;

	int GetMoviesID() const;
	void SetMoviesID(int moviesId);
	std::string GetType() const;
	void SetType(const std::string& type);
	std::string GetTitle() const;
	void SetTitle(const std::string& title);
	std::string GetDirector() const;
	void SetDirector(const std::string& director);
	int GetReleaseYear() const;
	void SetReleaseYear(int releaseYear);
	std::string GetCountry() const;
	void SetCountry(const std::string& country);
	std::string GetDateAdded();
	void SetDateAdded(const std::string& dateAdded);
	uint8_t GetRating() const;
	void SetRating(uint8_t rating);
	int GetDuration() const;
	void SetDuration(int duration);
	std::string GetDescription();
	void SetDescription(const std::string& description);
};

