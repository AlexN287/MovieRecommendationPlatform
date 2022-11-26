#include "Login.h"

Login::Login(const std::string& username, const std::string& password) : m_username{username}, m_password{password}
{}

void Login::SetUsername(const std::string& username)
{
	this->m_username = username;
}

std::string Login::GetUsername() const
{
	return m_username;
}

void Login::SetPassword(const std::string& password)
{
	this->m_password = password;
}

std::string Login::GetPassword() const
{
	return m_password;
}

bool Login::checkUser()
{
	using namespace sqlite_orm;
	namespace sql = sqlite_orm;
	Database db;
	auto userUsername = db.m_storage.select(columns(&User::GetUsername),
		sql::where(c(&User::GetUsername)==m_username));
	auto userPassword = db.m_storage.select(columns(&User::GetPassword),
		sql::where(c(&User::GetPassword) == m_password));

	if(userUsername.empty())

	//sql::where(c(&Book::category) == category));

	return false;
}
