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
    //Database::GetInstance()->RemoveElement<Wishlist>(user.GetUserId());
    //Database::GetInstance()->RemoveElement<WatchedList>(user.GetUserId());
    //Database::GetInstance()->RemoveElement<UserRating>(user.GetUserId());
    //Database::GetInstance()->RemoveElement<LikedGenre>(user.GetUserId());
    //Database::GetInstance()->RemoveElement<LikedActors>(user.GetUserId());
    //Database::GetInstance()->RemoveElement<Recommandation>(user.GetUserId());
    //Database::GetInstance()->RemoveElement<User>(user.GetUserId());
}
