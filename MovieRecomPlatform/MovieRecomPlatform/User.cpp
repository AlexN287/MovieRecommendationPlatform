#include "User.h"

User::User(int userId, std::string username, std::string password) : 
	m_userId{userId},
	m_username{username},
	m_password{password}
{
}

int User::GetUserId() const
{
	return this->m_userId;
}

std::string User::GetUsername() const
{
	return this->m_password;
}

std::string User::GetPassword() const
{
	return this->m_password;
}

void User::SetUserId(int userId)
{
	this->m_userId = userId;
}

void User::SetUsername(std::string userName)
{
	this->m_username = userName;
}

void User::SetPassword(std::string passWord)
{
	this->m_password = passWord;
}


