#pragma once
#include <iostream>
#include "User.h"

class SignUp
{
	enum class SignUpStatus
	{
		Successful,
		ExistentUser,
		Error
	};

	std::string m_username;
	std::string m_password;
	std::string m_birthdate;
	std::string m_gender;
public:
	SignUp();
	User createUser();
	bool existentUsername(const std::string& username);
	void addUserInDatabase(const User& user);
	std::string SignUpStatusToString(SignUp::SignUpStatus status);
};