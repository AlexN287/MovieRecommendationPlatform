#include "WatchedList.h"

WatchedList::WatchedList(std::unique_ptr<int> userId, std::unique_ptr<int> moviesId):
	m_userID{std::move(userId)},m_moviesID{std::move(moviesId)}, 
	m_watchedListId{ 0 }{}

WatchedList::WatchedList(const WatchedList& watchedList) :
	m_userID(std::make_unique<int>(*watchedList.m_userID)),
	m_moviesID(std::make_unique<int>(*watchedList.m_moviesID)),
	m_watchedListId(watchedList.m_watchedListId)
{
}

const std::unique_ptr<int>& WatchedList::GetUserID() const
{
	return m_userID;
}

const std::unique_ptr<int>& WatchedList::GetMoviesID() const
{
	return m_moviesID;
}

int WatchedList::GetWatchedListId() const
{
	return m_watchedListId;
}

void WatchedList::SetUserID(std::unique_ptr<int> userID)
{
	m_userID = std::move(userID);
}

void WatchedList::SetMoviesID(std::unique_ptr<int> moviesID)
{
	m_moviesID = std::move(moviesID);
}

void WatchedList::SetWatchedListId(int watchedListId)
{
	m_watchedListId = watchedListId;
}

