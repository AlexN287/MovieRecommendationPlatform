#include "Wishlist.h"

Wishlist::Wishlist(std::unique_ptr<int> userId, std::unique_ptr<int> moviesId):
	m_userID{ std::move(userId) }, m_moviesID{ std::move(moviesId) },
	m_wishlistID{0}
{}
Wishlist::Wishlist(const Wishlist& wishList) :
	m_userID(std::make_unique<int>(*wishList.m_userID)),
	m_moviesID(std::make_unique<int>(*wishList.m_moviesID)),
	m_wishlistID(wishList.m_wishlistID)
{
}
const std::unique_ptr<int>& Wishlist::GetUserID() const
{
	return m_userID;
}
const std::unique_ptr<int>& Wishlist::GetMoviesID() const
{
	return m_moviesID;
}
int Wishlist::GetWishlistID() const
{
	return m_wishlistID;
}
void Wishlist::SetUserID(std::unique_ptr<int> userID)
{
	m_userID = std::move(userID);
}
void Wishlist::SetMoviesID(std::unique_ptr<int> moviesID)
{
	m_moviesID = std::move(moviesID);
}

void Wishlist::SetWishlistID(int wishlistID)
{
	m_wishlistID = wishlistID;
}
