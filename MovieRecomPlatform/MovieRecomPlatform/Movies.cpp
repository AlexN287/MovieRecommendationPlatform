#include "Movies.h"

Movies::Movies(std::string type, std::string title, std::string director, std::string cast,
	 std::string country, std::string dateAdded, int releaseYear , std::string rating, int duration,
	std::string genres, std::string description) :
	m_moviesId{ 0 }, //TODO
	m_type{ type },
	m_title{ title },
	m_director{ director },
	m_cast{cast},
	m_releaseYear{ releaseYear },
	m_country{ country },
	m_dateAdded{dateAdded},
	m_rating{ rating },
	m_duration{ duration },
	m_genres{genres},
	m_description{description}
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

void Movies::SetTitle( std::string title)
{
	m_title = title;
}

std::string Movies::GetDirector() const
{
	return m_director;
}

void Movies::SetDirector( std::string director)
{
	m_director = director;
}

std::string Movies::GetCast() const
{
	return m_cast;
}

void Movies::SetCast(std::string cast)
{
	m_cast = cast;
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

void Movies::SetCountry( std::string country)
{
	m_country = country;
}

std::string Movies::GetDateAdded() const
{
	return m_dateAdded;
}

void Movies::SetDateAdded(std::string dateAdded)
{
	m_dateAdded = dateAdded;
}

std::string Movies::GetRating() const
{
	return m_rating;
}

void Movies::SetRating(std::string rating)
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

std::string Movies::GetGenres() const
{
	return m_genres;
}

void Movies::SetGenres(std::string genres)
{
	m_genres = genres;
}

std::string Movies::GetDescription() const
{
	return m_description;
}

void Movies::SetDescription(std::string description)
{
	m_description = description;
}
