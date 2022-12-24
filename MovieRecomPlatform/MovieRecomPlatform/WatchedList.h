#pragma once
#include <memory>
class WatchedList
{
private:
	std::unique_ptr<int> m_userID;
	std::unique_ptr<int> m_moviesID;

public:
	WatchedList() = default;
	WatchedList(std::unique_ptr<int> userId, std::unique_ptr<int> moviesId);
	WatchedList(const WatchedList& watchedList);
	~WatchedList() = default;

	const std::unique_ptr<int>& GetUserID() const;
	const std::unique_ptr<int>& GetMoviesID() const;
	void SetUserID(std::unique_ptr<int> userID);
	void SetMoviesID(std::unique_ptr<int> moviesID);
};

