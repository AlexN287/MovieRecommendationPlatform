#include "MovieGenre.h"

#include "MovieGenre.h"

MovieGenre::MovieGenre(std::unique_ptr<int> genreId, std::unique_ptr<int> moviesId) :
	m_genreId{ std::move(genreId) },
	m_moviesId{ std::move(moviesId) }
{
}

const std::unique_ptr<int>& MovieGenre::GetGenreId() const
{
	return m_genreId;
}

void MovieGenre::SetGenreId(std::unique_ptr<int> genreId)
{
	m_genreId = std::move(genreId);
}

const std::unique_ptr<int>& MovieGenre::GetMoviesId() const
{
	return m_moviesId;
}

void MovieGenre::SetMoviesId(std::unique_ptr<int> moviesId)
{
	m_moviesId = std::move(moviesId);
}
