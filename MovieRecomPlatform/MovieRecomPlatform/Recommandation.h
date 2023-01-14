#pragma once
#include <memory>
class Recommandation
{
	std::unique_ptr<int> m_userId;
	std::unique_ptr<int> m_movieId;
	int m_recommandationId;

public:
	Recommandation() = default;
	Recommandation(std::unique_ptr<int> userId, std::unique_ptr<int> moviesId);
	Recommandation(const Recommandation& recommandation);
	~Recommandation() = default;

	const std::unique_ptr<int>& GetUserID() const;
	const std::unique_ptr<int>& GetMovieID() const;
	int GetRecommandationID() const;
	void SetUserID(std::unique_ptr<int> userId);
	void SetMovieID(std::unique_ptr<int> movieId);
	void SetRecommandationID(int recommandationId);

};

