#pragma once
#include <memory>
#include<string>

class LikedGenre
{
private:
	std::unique_ptr<int> m_userID;
	std::string m_genre;
	int m_likedGenreID;

public:
	LikedGenre() = default;
	LikedGenre(std::unique_ptr<int> userId, std::string genre);
	LikedGenre(const LikedGenre& likedGenre);
	~LikedGenre() = default;

	const std::unique_ptr<int>& GetUserID() const;
	int GetUserIDValue() const;
	int GetLikedGenreID() const;
	std::string GetGenre() const;
	void SetUserID(std::unique_ptr<int> userID);
	void SetGenre(std::string genre);
	void SetLikedGenreID(int likedGenreID);
};

