#include "Wishlist.h"

Wishlist::Wishlist(std::unique_ptr<int> userId, std::unique_ptr<int> moviesId):
	m_userID{ std::move(userId) }, m_moviesID{ std::move(moviesId) }{}
const std::unique_ptr<int>& Wishlist::GetUserID() const
{
	return m_userID;
}
const std::unique_ptr<int>& Wishlist::GetMoviesID() const
{
	return m_moviesID;
}
void Wishlist::SetUserID(std::unique_ptr<int> userID)
{
	m_userID = std::move(userID);
}
void Wishlist::SetMoviesID(std::unique_ptr<int> moviesID)
{
	m_moviesID = std::move(moviesID);
}