#include "SignUp.h"
#include"Database.h"
#include <regex>

SignUp::SignUp() {
	User user = createUser();
	addUserInDatabase(user);
	for (User u : Database::GetInstance()->GetElements<User>())
		if (u.GetUsername() == user.GetUsername())
			newUserPreferences(u.GetUserId());
}

User SignUp::createUser() {
	std::cout << "Username: "; std::cin >> m_username;

	std::regex regex_exp("[^a-zA-Z0-9]");
	std::smatch m;
	while (std::regex_search(m_username, m, regex_exp)) {
		std::cout << SignUpStatusToString(SignUp::SignUpStatus::SpecialCharacters);
		std::cout << "Username: "; std::cin >> m_username;
	}

	while (existentUsername(m_username)) {
		std::cout << SignUpStatusToString(SignUp::SignUpStatus::ExistentUser);
		std::cout << "Username: "; std::cin >> m_username;
	}
	std::cout << "Password: "; std::cin >> m_password;

	regex_exp = "^(0[1-9]|[12][0-9]|3[01])[-\/\.](0[1-9]|1[012])[-\/\.](19|20)[0-9][0-9]$";
	std::cout << "Birthdate: "; std::cin >> m_birthdate;
	while (!std::regex_match(m_birthdate, regex_exp)) {
		std::cout << SignUpStatusToString(SignUp::SignUpStatus::InvalidDate);
		std::cout << "Birthdate: "; std::cin >> m_birthdate;
	}

	std::cout << "Gender: "; std::cin >> m_gender;
	User newUser(m_username, m_password, m_birthdate, m_gender);
	return newUser;
}

bool SignUp::existentUsername(const std::string& username) {
	using namespace sqlite_orm;
	namespace sql = sqlite_orm;

	auto userTable = Database::GetInstance()->GetElements<User>();
	for (int i = 0; i < userTable.size(); i++)
	{
		if (userTable[i].GetUsername() == m_username)
			return true;
	}
	return false;
}

void SignUp::addUserInDatabase(const User& user) {
	Database::GetInstance()->InsertElement(user);
	if (existentUsername(user.GetUsername()))
		std::cout << SignUpStatusToString(SignUp::SignUpStatus::Successful);
	else
		std::cout << SignUpStatusToString(SignUp::SignUpStatus::Error);
}

void SignUp::newUserPreferences(const int& userId) {
	std::string genreName;
	std::cout << "Give us some of your favourite genres (type 0 to skip): ";
	std::getline(std::cin, genreName);
	while (genreName != "0") {
		if (!genreName.empty()) {
			std::unique_ptr<int> userIdPtr = std::make_unique<int>(userId);
			LikedGenre lg(std::move(userIdPtr), genreName);
			//Database::GetInstance()->getStorage()->insert(lg);
			Database::GetInstance()->InsertForeignKey(lg);
		}
		std::getline(std::cin, genreName);
	}
	
	std::string actorName;
	std::cout << "Give us some of your favourite actors (type 0 to skip): ";
	std::getline(std::cin, actorName);
	while (actorName != "0") {
		if (!actorName.empty()) {
			std::unique_ptr<int> userIdPtr = std::make_unique<int>(userId);
			LikedActors la(std::move(userIdPtr), actorName);
			//Database::GetInstance()->getStorage()->insert(la);
			Database::GetInstance()->InsertForeignKey(la);
		}
		std::getline(std::cin, actorName);
	}
}

std::string SignUp::SignUpStatusToString(SignUp::SignUpStatus status) {
	switch (status)
	{
	case SignUp::SignUpStatus::Successful:
		return "Successful\n";
	case SignUp::SignUpStatus::ExistentUser:
		return "The username is already used\n";
	case SignUp::SignUpStatus::SpecialCharacters:
		return "It can not contain special characters\n";
	case SignUp::SignUpStatus::InvalidDate:
		return "Incorrect date format\n";
	case SignUp::SignUpStatus::Error:
		return "Error\n";
	default:
		return "";
	}
}