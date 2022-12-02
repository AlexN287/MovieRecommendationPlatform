#pragma once
#include <memory>
class LikedGenre
{
private:
	std::unique_ptr<int> m_userID;
	std::unique_ptr<int> m_genreID;

public:
	LikedGenre() = default;
	LikedGenre(std::unique_ptr<int> userId, std::unique_ptr<int> genreId);
	~LikedGenre() = default;

	const std::unique_ptr<int>& GetUserID() const;
	const std::unique_ptr<int>& GetGenreID() const;
	void SetUserID(std::unique_ptr<int> userID);
	void SetGenreID(std::unique_ptr<int> genreID);
};

