#include "Actor.h"

Actor::Actor(int actorId, std::string fullName) :
	m_actorId{ actorId }, m_fullName{ fullName }{}

int Actor::GetActorId() const {
	return this->m_actorId;
}
std::string Actor::GetFullName() const {
	return this->m_fullName;
}
void Actor::SetActorId(int actorId) {
	this->m_actorId = actorId;
}
void Actor::SetFullName(std::string fullName) {
	this->m_fullName = fullName;
}