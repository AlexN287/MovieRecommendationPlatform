#include "LikedActors.h"

LikedActors::LikedActors(std::unique_ptr<int> userId, std::string actor) :
	m_userId{ std::move(userId) }, m_actor{ actor }{}

std::string LikedActors::GetActor() const
{
	return m_actor;
}

const std::unique_ptr<int>& LikedActors::GetUserId() const
{
	return m_userId;
}

void LikedActors::SetActor(std::string actor)
{
	this->m_actor = actor;
}

void LikedActors::SetUserId(std::unique_ptr<int> userId)
{
	m_userId = std::move(userId);
}
