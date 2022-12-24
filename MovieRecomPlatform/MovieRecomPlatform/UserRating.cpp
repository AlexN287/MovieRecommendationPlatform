#include "UserRating.h"

UserRating::UserRating(std::unique_ptr<int> userId, std::unique_ptr<int> movieId, int rating) : 
	m_userId{std::move(userId)},
	m_movieId{std::move(movieId)},
	m_rating{rating}
{
}

UserRating::UserRating(const UserRating& userRating) :
	m_userId(std::make_unique<int>(*userRating.m_userId)),
	m_movieId(std::make_unique<int>(*userRating.m_movieId)),
	m_rating(userRating.m_rating)
{
}

const std::unique_ptr<int>& UserRating::GetUserId() const
{
	return m_userId;
}

const std::unique_ptr<int>& UserRating::GetMovieId() const
{
	return m_movieId;
}

int UserRating::GetRating() const
{
	return this->m_rating;
}

void UserRating::SetUserId(std::unique_ptr<int> userId)
{
	this->m_userId = std::move(userId);
}

void UserRating::SetMovieId(std::unique_ptr<int> movieId)
{
	this->m_movieId = std::move(movieId);
}

void UserRating::SetRating(int rating)
{
	this->m_rating = rating;
}
