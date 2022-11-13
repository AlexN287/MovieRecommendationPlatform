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
	User(const User& user) = default;
	~User() = default;
	int GetUserId() const;
	std::string GetUsername() const;
	std::string GetPassword() const;
	void SetUserId(int userId);
	void SetUsername(std::string userName);
	void SetPassword(std::string passWord);

};

