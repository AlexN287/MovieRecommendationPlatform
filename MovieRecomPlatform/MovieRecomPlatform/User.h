#pragma once
#include <string>
class User
{
public:
	int m_userId;
	std::string m_username;
	std::string m_password;

	User(int userId, std::string username, std::string password);
	int GetUserId();
	std::string GetUsername();
	std::string GetPassword();
	void SetUserId(int userId);
	void SetUsername(std::string userName);
	void SetPassword(std::string passWord);

};

