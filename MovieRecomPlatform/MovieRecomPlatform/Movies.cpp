#include "Movies.h"

Movies::Movies(int moviesId, std::string type, std::string title, std::string director, int releaseYear,
	 std::string country, uint8_t rating, int duration) :
	m_moviesId{ moviesId },
	m_type{ type },
	m_title{ title },
	m_director{ director },
	m_releaseYear{ releaseYear },
	m_country{ country },
	m_rating{ rating },
	m_duration{ duration }
{
}

int Movies::GetMoviesID() const
{
	return m_moviesId;
}

void Movies::SetMoviesID(int moviesId)
{
	m_moviesId = moviesId;
}

std::string Movies::GetType() const
{
	return m_type;
}

void Movies::SetType(std::string type)
{
	m_type = type;
}

std::string Movies::GetTitle() const
{
	return m_title;
}

void Movies::SetTitle(std::string title)
{
	m_title = title;
}

std::string Movies::GetDirector() const
{
	return m_director;
}

void Movies::SetDirector(std::string director)
{
	m_director = director;
}

int Movies::GetReleaseYear() const
{
	return m_releaseYear;
}

void Movies::SetReleaseYear(int releaseYear)
{
	m_releaseYear = releaseYear;
}

std::string Movies::GetCountry() const
{
	return m_country;
}

void Movies::SetCountry(std::string country)
{
	m_country = country;
}

uint8_t Movies::GetRating() const
{
	return m_rating;
}

void Movies::SetRating(uint8_t rating)
{
	m_rating = rating;
}

int Movies::GetDuration() const
{
	return m_duration;
}

void Movies::SetDuration(int duration)
{
	m_duration = duration;
}
