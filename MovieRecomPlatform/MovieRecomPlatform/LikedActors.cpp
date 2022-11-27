#include "LikedActors.h"

LikedActors::LikedActors(std::unique_ptr<int> userId, std::unique_ptr<int> actorId) :
	m_userId{ std::move(userId) }, m_actorId{ std::move(actorId) }{}

const std::unique_ptr<int>& LikedActors::GetActorId() const
{
	return m_actorId;
}

const std::unique_ptr<int>& LikedActors::GetUserId() const
{
	return m_userId;
}

void LikedActors::SetActorId(std::unique_ptr<int> actorId)
{
	m_actorId = std::move(actorId);
}

void LikedActors::SetUserId(std::unique_ptr<int> userId)
{
	m_userId = std::move(userId);
}
