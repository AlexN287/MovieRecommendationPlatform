#pragma once
#include <string>
#include"..\MovieRecomPlatform\User.h"
#include"..\MovieRecomPlatform\Database.h"

#ifdef LOGIN_EXPORTS
#define LOGIN_API __declspec(dllexport)
#else 
#define LOGIN_API __declspec(dllimport)
#endif // LOGGING_EXPORTS

class LOGIN_API Login
{

	enum class AuthentificationStatus
	{
		Successful,
		NotRegistered,
		WrongPassword,
		Error
	};

private:
	std::string m_username;
	std::string m_password;

public:
	Login(const std::string& username, const std::string& password);

	void SetUsername(const std::string& username);
	std::string GetUsername() const;
	void SetPassword(const std::string& password);
	std::string GetPassword() const;

	bool checkUser();
	void showUser();
};


