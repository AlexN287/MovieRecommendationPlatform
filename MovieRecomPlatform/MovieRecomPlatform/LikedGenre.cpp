#include "LikedGenre.h"

LikedGenre::LikedGenre(std::unique_ptr<int> userId, std::unique_ptr<int> genreId) :
	m_userID{ std::move(userId) }, m_genreID{ std::move(genreId) } {}

const std::unique_ptr<int>& LikedGenre::GetUserID() const
{
	return m_userID;
}

const std::unique_ptr<int>& LikedGenre::GetGenreID() const
{
	return m_genreID;
}

void LikedGenre::SetUserID(std::unique_ptr<int> userID)
{
	m_userID = std::move(userID);
}

void LikedGenre::SetGenreID(std::unique_ptr<int> genreID)
{
	m_genreID = std::move(genreID);
}
