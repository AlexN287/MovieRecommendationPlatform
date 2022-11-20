#include "WatchedList.h"

WatchedList::WatchedList(std::unique_ptr<int> userId, std::unique_ptr<int> moviesId):
	m_userID{std::move(userId)},m_moviesID{std::move(moviesId)} {}

const std::unique_ptr<int>& WatchedList::GetUserID() const
{
	return m_userID;
}

const std::unique_ptr<int>& WatchedList::GetMoviesID() const
{
	return m_moviesID;
}

void WatchedList::SetUserID(std::unique_ptr<int> userID)
{
	m_userID = std::move(userID);
}

void WatchedList::SetMoviesID(std::unique_ptr<int> moviesID)
{
	m_moviesID = std::move(moviesID);
}

