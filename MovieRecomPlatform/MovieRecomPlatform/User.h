#pragma once
#include <string>
class User
{
private:
	int m_userId;
	std::string m_username;
	std::string m_password;

public:

	User(int userId, std::string username, std::string password);
	int GetUserId();
	std::string GetUsername();
	std::string GetPassword();

};

