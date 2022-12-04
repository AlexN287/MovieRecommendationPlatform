#include "LikedGenre.h"

LikedGenre::LikedGenre(std::unique_ptr<int> userId, std::string genre) :
	m_userID{ std::move(userId) }, m_genre{ genre } {}

const std::unique_ptr<int>& LikedGenre::GetUserID() const
{
	return m_userID;
}

std::string LikedGenre::GetGenre() const
{
	return m_genre;
}

void LikedGenre::SetUserID(std::unique_ptr<int> userID)
{
	m_userID = std::move(userID);
}

void LikedGenre::SetGenre(std::string genre)
{
	this->m_genre = genre;
}
