//#include "SignUp.h"
////#include"Database.h"
//
//SignUp::SignUp() {
//	addUserInDatabase(createUser());
//}
//User SignUp::createUser() {
//	std::cout << "Username: "; std::cin >> m_username;
//	while (existentUsername(m_username)) {
//		std::cout << SignUpStatusToString(SignUp::SignUpStatus::ExistentUser);
//		std::cout << "Username: "; std::cin >> m_username;
//	}
//	std::cout << "Password: "; std::cin >> m_password;
//	std::cout << "Birthdate: "; std::cin >> m_birthdate;
//	std::cout << "Gender: "; std::cin >> m_gender;
//	User newUser(m_username, m_password, m_birthdate, m_gender);
//	return newUser;
//}
//
//bool SignUp::existentUsername(const std::string& username) {
//	/*using namespace sqlite_orm;
//	namespace sql = sqlite_orm;
//	Database db;
//
//	auto User = db.m_storage.select(columns(&User::GetUsername), sql::where(c(&User::GetUsername) == m_username));
//	return !User.empty();*/
//}
//
//void SignUp::addUserInDatabase(const User& user) {
//	/*using namespace sqlite_orm;
//	namespace sql = sqlite_orm;
//	Database db;*/
//
//	db.m_storage.insert(user);
//	if (existentUsername(user.GetUsername()))
//		std::cout << SignUpStatusToString(SignUp::SignUpStatus::Successful);
//	else
//		std::cout << SignUpStatusToString(SignUp::SignUpStatus::Error);
//}
//
//std::string SignUp::SignUpStatusToString(SignUp::SignUpStatus status) {
//	switch (status)
//	{
//	case SignUp::SignUpStatus::Successful:
//		return "Successful\n";
//	case SignUp::SignUpStatus::ExistentUser:
//		return "The username is already used\n";
//	case SignUp::SignUpStatus::Error:
//		return "Error\n";
//	default:
//		return "";
//	}
//}