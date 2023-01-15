#pragma once
#include <string>
#include "Database.h"
class Login
{

private:
	std::string m_username;
	std::string m_password;

public:
	Login(const std::string& username, const std::string& password);
	Login(const Login& login);
	Login& operator=(const Login& login);

	void SetUsername(const std::string& username);
	std::string GetUsername() const;
	void SetPassword(const std::string& password);
	std::string GetPassword() const;
	bool checkUser(const User& user);
	User getUser();
	static void updateUserUsername(User& user, const std::string& username);
	static void updateUserPassword(User& user, const std::string& password);
	static void deleteUser(User& user);
};

