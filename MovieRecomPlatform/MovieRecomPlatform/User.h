#pragma once
#include <string>
class User
{
private:
	int m_userId;
	std::string m_username;
	std::string m_password;
	std::string birthdate;
	std::string gender;

public:
	User(int userId, std::string username, std::string password);
	User(const User& user) = default;
	~User() = default;
	int GetUserId() const;
	std::string GetUsername() const;
	std::string GetPassword() const;
	std::string GetPassword() const;
	std::string GetGender() const;
	void SetUserId(int userId);
	void SetUsername(std::string username);
	void SetPassword(std::string password);
	void SetBirthdate(std::string birthdate);
	void SetGender(std::string gender);

};

