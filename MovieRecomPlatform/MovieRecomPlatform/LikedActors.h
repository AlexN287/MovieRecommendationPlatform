#pragma once
#include <memory>

class LikedActors
{
private:
	std::unique_ptr<int> m_userId;
	std::unique_ptr<int> m_actorId;
public:
	LikedActors(std::unique_ptr<int> userId, std::unique_ptr<int>actorId);
	~LikedActors() = default;

	const std::unique_ptr<int>& GetActorId() const;
	const std::unique_ptr<int>& GetUserId() const;
	void SetActorId(std::unique_ptr<int> actorId);
	void SetUserId(std::unique_ptr<int> userId);
};

