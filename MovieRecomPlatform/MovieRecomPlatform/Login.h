#pragma once
#include <string>
#include "Database.h"
class Login
{
	enum class LoginStatus
	{
		Successful,
		NotRegistered,
		WrongPassword
	};

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
	std::string LoginStatusToString(Login::LoginStatus loginStatus);
	bool checkUser(const User& user);
	User getUser();
	void showUser(const User& user);
};

