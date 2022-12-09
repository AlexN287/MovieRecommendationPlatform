#pragma once
#include <memory>
class Recommandation
{
	std::unique_ptr<int> m_userId;
	std::unique_ptr<int> m_movieId;

public:
	Recommandation() = default;
	Recommandation(std::unique_ptr<int> userId, std::unique_ptr<int> moviesId);
	~Recommandation() = default;

	const std::unique_ptr<int>& GetUserID() const;
	const std::unique_ptr<int>& GetMovieID() const;
	void SetUserID(std::unique_ptr<int> userId);
	void SetMovieID(std::unique_ptr<int> movieId);

};

