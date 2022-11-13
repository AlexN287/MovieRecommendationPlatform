#include "Wishlist.h"

const std::unique_ptr<int>& Wishlist::GetUserID() const{
	return m_userID;
}
const std::unique_ptr<int>& Wishlist::GetMoviesID() const {
	return m_moviesID;
}
void Wishlist::SetUserID(std::unique_ptr<int> userID) {
	this->m_userID = std::move(userID);
}
void Wishlist::SetMoviesID(std::unique_ptr<int> moviesID) {
	this->m_moviesID = std::move(moviesID);
}