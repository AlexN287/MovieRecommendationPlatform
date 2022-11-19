#include "MovieActor.h"

MovieActor::MovieActor(std::unique_ptr<int> actorId, std::unique_ptr<int> moviesId) :
	m_actorId{ std::move(actorId) }, m_moviesId{ std::move(moviesId) }{}

const std::unique_ptr<int>& MovieActor::GetActorId() const {
	return this->m_actorId;
}
const std::unique_ptr<int>& MovieActor::GetMoviesId() const {
	return m_moviesId;
}
void MovieActor::SetActorId(std::unique_ptr<int> actorId) {
	this->m_actorId = std::move(actorId);
}
void MovieActor::SetMoviesId(std::unique_ptr<int> moviesId) {
	this->m_moviesId = std::move(moviesId);
}