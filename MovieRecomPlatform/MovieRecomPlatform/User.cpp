#include "User.h"

User::User(const std::string& username, const std::string& password, const std::string& birthdate, const std::string& gender) :
	m_username{ username },
	m_password{ password },
	m_birthdate{ birthdate },
	m_gender{ gender },
	m_userId{ 0 } //TODO
{
	
}

int User::GetUserId() const
{
	return this->m_userId;
}

std::string User::GetUsername() const
{
	return this->m_username;
}

std::string User::GetPassword() const
{
	return this->m_password;
}

std::string User::GetBirthdate() const
{
	return this->m_birthdate;
}

std::string User::GetGender() const
{
	return this->m_gender;
}

void User::SetUserId(int userId)
{
	this->m_userId = userId;
}

void User::SetUsername(std::string username)
{
	this->m_username = username;
}

void User::SetPassword(std::string password)
{
	this->m_password = password;
}

void User::SetBirthdate(std::string birthdate)
{
	this->m_birthdate = birthdate;
}

void User::SetGender(std::string gender)
{
	this->m_gender = gender;
}


