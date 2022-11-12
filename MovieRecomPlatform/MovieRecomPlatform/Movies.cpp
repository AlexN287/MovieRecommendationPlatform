#include "Movies.h"

Movies::Movies(int moviesId, std::string type, std::string title, std::string director, int releaseYear,
	std::string cast, std::string country, uint8_t rating, int duration) :
	m_moviesId{ moviesId },
	m_type{ type },
	m_title{ title },
	m_director{ director },
	m_releaseYear{ releaseYear },
	m_cast{ cast },
	m_country{ country },
	m_rating{ rating },
	m_duration{ duration }
{
}

int Movies::GetMoviesID() const
{
	return m_moviesId;
}

std::string Movies::GetType() const
{
	return m_type;
}

std::string Movies::GetTitle() const
{
	return m_title;
}

std::string Movies::GetDirector() const
{
	return m_director;
}

int Movies::GetReleaseYear() const
{
	return m_releaseYear;
}

std::string Movies::GetCast() const
{
	return m_cast;
}

std::string Movies::GetCountry() const
{
	return m_country;
}

uint8_t Movies::GetRating() const
{
	return m_rating;
}

int Movies::GetDuration() const
{
	return m_duration;
}
