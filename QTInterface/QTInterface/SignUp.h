#pragma once
#include <iostream>
#include "User.h"
#include "LikedGenre.h"
#include "LikedActors.h"
#include "Application.h"

class SignUp
{
	enum class SignUpStatus
	{
		Successful,
		ExistentUser,
		SpecialCharacters,
		InvalidDate,
		Error
	};

	User currentUser;
public:
	SignUp(std::string username, std::string password, std::string birthdate, std::string gender);
	User createUser(std::string username, std::string password, std::string birthdate, std::string gender);
	static bool existentUsername(const std::string& username);
	static bool hasSpecialCharacters(const std::string& username);
	void addUserInDatabase(const User& user);
	std::string SignUpStatusToString(SignUp::SignUpStatus status);
	User getCurrentUser();
	static void newUserPreferences(const User& user, const std::vector<std::string>& genres);
};