#include "Database.h"
#include "Login.h"
#include "SignUp.h"
#include <iostream>

int main()
{
	Database db;

	/*User user("Name", "Password", "10.10.2010", "Female");

	//db.m_storage.insert(user);

	std::string username, password;

	std::cout << "Login: \n";

	std::cout << "Enter username: ";
	std::cin >> username;
	std::cout << "\n";
	std::cout << "Enter password: ";
	std::cin >> password;
	std::cout << "\n";

	Login firstLog(username, password);
	*/
	//SignUp();
	std::string username, password;
	std::cout << "Login: \n";

	std::cout << "Enter username: ";
	std::cin >> username;
	std::cout << "\n";
	std::cout << "Enter password: ";
	std::cin >> password;
	std::cout << "\n";

	Login firstLog(username, password);
	return 0;
}