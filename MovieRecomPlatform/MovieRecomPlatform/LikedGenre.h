#pragma once
#include <memory>
#include<string>

class LikedGenre
{
private:
	std::unique_ptr<int> m_userID;
	std::string m_genre;

public:
	LikedGenre() = default;
	LikedGenre(std::unique_ptr<int> userId, std::string genre);
	~LikedGenre() = default;

	const std::unique_ptr<int>& GetUserID() const;
	std::string GetGenre() const;
	void SetUserID(std::unique_ptr<int> userID);
	void SetGenre(std::string genre);
};

