#pragma once
#include <string>
class User
{
private:
	int m_userId; //TODO
	std::string m_username;
	std::string m_password;
	std::string m_birthdate;
	std::string m_gender;

public:

	User() = default;
	User(const std::string& username,const std::string& password,const std::string& birthdate,const std::string& gender);
	User(const User& user) = default;
	~User() = default;
	int GetUserId() const;
	std::string GetUsername() const;
	std::string GetPassword() const;
	std::string GetBirthdate() const;
	std::string GetGender() const;
	void SetUserId(int userId);
	void SetUsername(std::string username);
	void SetPassword(std::string password);
	void SetBirthdate(std::string birthdate);
	void SetGender(std::string gender);

};

