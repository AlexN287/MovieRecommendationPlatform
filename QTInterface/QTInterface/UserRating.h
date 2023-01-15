#pragma once
#include <memory>
class UserRating
{
private:
	std::unique_ptr <int> m_userId;
	std::unique_ptr <int> m_movieId;
	int m_rating;
	int m_userRatingId;

public:
	UserRating() = default;
	UserRating(std::unique_ptr <int> userId, std::unique_ptr <int> movieId, int rating);
	UserRating(const UserRating& userRating);
	UserRating& operator=(const UserRating& userRating);
	~UserRating() = default;
	const std::unique_ptr <int>& GetUserId() const;
	const std::unique_ptr <int>& GetMovieId() const;
	int GetUserRatingId() const;
	int GetRating() const;
	void SetUserId(std::unique_ptr <int> userId);
	void SetMovieId(std::unique_ptr <int> movieId);
	void SetRating(int rating);
	void SetUserRatingId(int userRatingId);

};

