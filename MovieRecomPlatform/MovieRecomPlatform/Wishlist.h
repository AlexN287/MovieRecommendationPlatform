#pragma once
#include <memory>
class Wishlist {
private:
	std::unique_ptr<int> m_userID;
	std::unique_ptr<int> m_moviesID;

public:
	Wishlist() = default;
	Wishlist(std::unique_ptr<int> userId, std::unique_ptr<int> moviesId);
	~Wishlist() = default;

	const std::unique_ptr<int>& GetUserID() const;
	const std::unique_ptr<int>& GetMoviesID() const;
	void SetUserID(std::unique_ptr<int> userIDS);
	void SetMoviesID(std::unique_ptr<int> moviesID);
};
