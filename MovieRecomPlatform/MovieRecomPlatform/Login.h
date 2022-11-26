#pragma once
#include <string>
class Login
{
	enum class AuthentificationStatus
	{
		Successful,
		NotRegistered,
		WrongPassword,
		Error
	};

public:
	std::string m_username;
	std::string m_password;

public:
	Login(const std::string& username, const std::string& password);

	void SetUsername(const std::string& username);
	std::string GetUsername() const;
	void SetPassword(const std::string& password);
	std::string GetPassword() const;

	inline auto checkUser();
	void showUser();
};

