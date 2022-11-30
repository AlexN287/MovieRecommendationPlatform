#pragma once
#include <string>
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

	void SetUsername(const std::string& username);
	std::string GetUsername() const;
	void SetPassword(const std::string& password);
	std::string GetPassword() const;
	std::string LoginStatusToString(Login::LoginStatus loginStatus);
	inline auto checkUser();
	void showUser();
};

