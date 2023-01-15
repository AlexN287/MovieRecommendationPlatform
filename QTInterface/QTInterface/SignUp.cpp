#include "SignUp.h"
#include"Database.h"
#include <regex>

SignUp::SignUp(std::string username, std::string password, std::string birthdate, std::string gender) {
	User user = createUser(username, password, birthdate,gender);
	addUserInDatabase(user);

	for(auto u : Database::GetInstance()->GetElements<User>())
		if (u.GetUsername() == user.GetUsername())
		{
			currentUser = u;
			break;
		}

	//int n = user.GetUserId();
	//Application a('a');
	//a.RecommendInitialMovies(user);
}

User SignUp::createUser(std::string username, std::string password, std::string birthdate, std::string gender) {

	User newUser(username, password, birthdate, gender);
	return newUser;
}


 bool SignUp::existentUsername(const std::string& username) {
	using namespace sqlite_orm;
	namespace sql = sqlite_orm;

	auto userTable = Database::GetInstance()->GetElements<User>();
	for (int i = 0; i < userTable.size(); i++)
	{
		if (userTable[i].GetUsername() == username)
			return true;
	}
	return false;
}

 bool SignUp::hasSpecialCharacters(const std::string& username)
 {
	 std::regex regex_exp("[^a-zA-Z0-9]");
	 std::smatch m;

	 if (std::regex_search(username, m, regex_exp))
		 return true;
	 return false;
 }

void SignUp::addUserInDatabase(const User& user) {
	Database::GetInstance()->InsertElement(user);
}

void SignUp::newUserPreferences(const User& user, const std::vector<std::string>& genres) {
	
	int userId = user.GetUserId();

	for (int i = 0; i < genres.size(); i++)
	{
		std::unique_ptr<int> userIdPtr = std::make_unique<int>(userId);
		Database::GetInstance()->InsertElement(LikedGenre(std::move(userIdPtr), genres[i]));
	}

}


User SignUp::getCurrentUser()
{
	return currentUser;
}
