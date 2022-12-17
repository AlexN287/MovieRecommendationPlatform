#include "Login.h"
#include<iostream>
#include<tuple>
#include<stdexcept>

Login::Login(const std::string& username, const std::string& password) : m_username{ username }, m_password{ password }
{
}

Login::Login(const Login& login)
{
    *this = login;
}

Login& Login::operator=(const Login& login)
{
    m_username = login.m_username;
    m_password = login.m_password;
    return *this;
}

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

std::string Login::LoginStatusToString(Login::LoginStatus loginStatus)
{
    switch (loginStatus)
    {
    case Login::LoginStatus::Successful:
        return "Successful \n";
        break;
    case Login::LoginStatus::NotRegistered:
        return "Not registered \n";
        break;
    case Login::LoginStatus::WrongPassword:
        return "Wrong password \n";
        break;
    default:
        return "Authentification error \n";
    }
}

bool Login::checkUser(const User& user)
{
    if (user.GetPassword().empty())
    {
        std::cout<<LoginStatusToString(LoginStatus::NotRegistered) << "\n";
        return false;
    }
    if (user.GetPassword() == m_password)
    {
        std::cout << LoginStatusToString(LoginStatus::Successful) << "\n";
        return true;
    }

    std::cout << LoginStatusToString(LoginStatus::WrongPassword) << "\n";
    return false;
    
}


