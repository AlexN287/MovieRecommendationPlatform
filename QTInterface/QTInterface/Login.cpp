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


bool Login::checkUser(const User& user)
{
    if (user.GetPassword().empty())
        return false;
    
    if (user.GetPassword() == m_password)
        return true;

    return false;
    
}

User Login::getUser()
{
    using namespace sqlite_orm;
    namespace sql = sqlite_orm;

    User userFound;
    auto user = Database::GetInstance()->GetElements<User>();
    for (int i = 0; i < user.size(); i++)
    {
        if (user[i].GetUsername() == m_username)
        {
            userFound = user[i];
            break;
        }
    }
    return userFound;
}

void Login::updateUserUsername(User& user, const std::string& username)
{
    user.SetUsername(username);

    Database::GetInstance()->UpdateElement(user);
}

void Login::updateUserPassword(User& user, const std::string& password)
{
    user.SetPassword(password);

    Database::GetInstance()->UpdateElement(user);
}

void Login::deleteUser(User& user)
{
    user.SetUsername("");
    user.SetPassword("User deleted");
    user.SetBirthdate("");
    user.SetGender("");

    Database::GetInstance()->UpdateElement(user);
}
