#include "Database.h"
#include "Login.h"
#include <iostream>

int main()
{
	Database db;

	User user("JosephStalin", "Bestruler46", "23.08.1899", "Male");

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

	return 0;
}