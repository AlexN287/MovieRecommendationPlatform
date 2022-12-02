//#include "Login.h"
////#include"Database.h"
//#include"User.h"
//#include<iostream>
//#include<tuple>
//#include<stdexcept>
//
//Login::Login(const std::string& username, const std::string& password) : m_username{ username }, m_password{ password }
//{
//    showUser();
//}
//
//void Login::SetUsername(const std::string& username)
//{
//	this->m_username = username;
//}
//
//std::string Login::GetUsername() const
//{
//	return m_username;
//}
//
//void Login::SetPassword(const std::string& password)
//{
//	this->m_password = password;
//}
//
//std::string Login::GetPassword() const
//{
//	return m_password;
//}
//
//std::string Login::LoginStatusToString(Login::LoginStatus loginStatus)
//{
//    switch (loginStatus)
//    {
//    case Login::LoginStatus::Successful:
//        return "Successful \n";
//        break;
//    case Login::LoginStatus::NotRegistered:
//        return "Not registered \n";
//        break;
//    case Login::LoginStatus::WrongPassword:
//        return "Wrong password \n";
//        break;
//    default:
//        return "Authentification error \n";
//    }
//}
//
//inline auto Login::checkUser()
//{
//    using namespace sqlite_orm;
//    namespace sql = sqlite_orm;
//    Database db;
//   
//    auto User= db.m_storage.select(columns(&User::GetUsername,&User::GetPassword,&User::GetBirthdate,&User::GetGender),
//        sql::where(c(&User::GetUsername) == m_username));
//    try {
//        if (User.empty())
//        {
//            throw LoginStatusToString(Login::LoginStatus::NotRegistered);
//        }
//        if (std::get<1>(User[0]) != m_password)
//        {
//            throw LoginStatusToString(Login::LoginStatus::WrongPassword);
//        }
//    }
//    catch (const std::string& exception)
//    {
//        std::cout << exception;
//        User.clear();
//    }
//        return User;
//}
//
//void Login::showUser()
//{
//    using loggedUser = decltype(checkUser());
//    loggedUser user;
//
//    try
//    {
//        user = checkUser();
//        if (user.empty())
//            throw std::string("Try again. \n");
//    }
//    catch (const std::string& exception)
//    {
//        std::cout << exception;
//        return;
//    }
//
//    std::cout << LoginStatusToString(Login::LoginStatus::Successful);
//    std::cout << "0 - Exit \n";
//    std::cout << "1 - Show username \n";
//    std::cout << "2 - Show birthdate \n";
//    std::cout << "3 - Show gender \n";
//
//    bool exitCondition = false;
//    while (!exitCondition)
//    {
//        int option;
//        std::cin >> option;
//
//        switch (option)
//        {
//        case 0:
//            exitCondition = true;
//            break;
//        case 1:
//            std::cout << std::get<0>(user[0]) << "\n";
//            break;
//        case 2:
//            std::cout << std::get<2>(user[0]) << "\n";
//            break;
//        case 3:
//            std::cout << std::get<3>(user[0]) << "\n";
//            break;
//        }
//    }
//}
