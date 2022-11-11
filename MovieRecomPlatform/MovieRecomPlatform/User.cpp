#include "User.h"

User::User(int userId, std::string username, std::string password) : 
	m_userId{userId},
	m_username{username},
	m_password{password}
{
}

int User::GetUserId()
{
	return this->m_userId;
}

std::string User::GetUsername()
{
	return this->m_password;
}

std::string User::GetPassword()
{
	return this->m_password;
}


