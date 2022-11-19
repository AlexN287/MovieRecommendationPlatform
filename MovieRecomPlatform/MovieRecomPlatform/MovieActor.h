#pragma once
#include <memory>
class MovieActor
{
	std::unique_ptr<int> m_actorId;
	std::unique_ptr<int> m_moviesId;
public:
	MovieActor(std::unique_ptr<int> actorId, std::unique_ptr<int> moviesId);
	~MovieActor() = default;

	const std::unique_ptr<int>& GetActorId() const;
	const std::unique_ptr<int>& GetMoviesId() const;
	void SetActorId(std::unique_ptr<int> actorId);
	void SetMoviesId(std::unique_ptr<int> moviesId);
};

