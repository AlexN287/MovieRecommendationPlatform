#include "SignUp.h"
#include"Database.h"

bool SignUp::existentUsername(const std::string& username) {
	using namespace sqlite_orm;
	namespace sql = sqlite_orm;
	Database db;

	auto User = db.m_storage.select(columns(&User::GetUsername), sql::where(c(&User::GetUsername) == m_username));
	return !User.empty();
}

void SignUp::addUserInDatabase(const User& user) {
	using namespace sqlite_orm;
	namespace sql = sqlite_orm;
	Database db;

	db.m_storage.insert(user);
	if (existentUsername(user.GetUsername()))
		std::cout << SignUpStatusToString(SignUp::SignUpStatus::Successful);
	else
		std::cout << SignUpStatusToString(SignUp::SignUpStatus::Error);
}

std::string SignUp::SignUpStatusToString(SignUp::SignUpStatus status) {
	switch (status)
	{
	case SignUp::SignUpStatus::Successful:
		return "Successful\n";
	case SignUp::SignUpStatus::ExistentUser:
		return "The username is already used\n";
	case SignUp::SignUpStatus::Error:
		return "Error\n";
	default:
		return "";
	}
}