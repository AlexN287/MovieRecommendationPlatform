#pragma once
#include <string>
class Actor
{
	int m_actorId;
	std::string m_fullName;
public:
	Actor() = default;
	Actor(int actorId, std::string fullName);
	Actor(const Actor& actor) = default;
	~Actor() = default;

	int GetActorId() const;
	std::string GetFullName() const;
	void SetActorId(int actorId);
	void SetFullName(std::string fullName);
};

