#include "Database.h"
#include "Login.h"
#include "SignUp.h"
#include "Application.h"
#include <iostream>

int main()
{

	//Database::GetInstance()->PopulateMovies("netflix_titles.csv");
	//Database::GetInstance()->PopulateGenres();

	Application a;

	std::vector<User> users = Database::GetInstance()->GetElements<User>();

	std::vector<Movies> movies = Database::GetInstance()->GetElements<Movies>();

	std::vector<Movies> mm = a.SearchMovie("taruto");

	for (int i = 0; i < mm.size(); i++)
	{
		std::cout << mm[i].GetTitle() << "\n";
	}

	/*auto m = a.SelectRandomMoviesFromRecommandation(users[1]);

	for (int i = 0; i < m.size(); i++)
	{
		std::cout << m[i].GetTitle() << "\n";
	}*/

	a.AddToWishList(users[4], movies[3]);
	/*std::vector<Recommandation> r = Database::GetInstance()->SelectUserRecommandation(users[4].GetUserId());

	for (int i = 0; i < r.size(); i++)
	{
		std::cout << *r[i].GetUserID() << " " << *r[i].GetMovieID() << "\n";
	}*/



	//a.RemoveFromWishlist(users[4], movies[0]);

	/*for (int i = 0; i < users.size(); i++)
		std::cout << users[i].GetUsername() << "\n";*/


	/*std::vector<Movies> movies = a.SelectRandomMoviesFromRecommandation(users[1]);

	for (int i = 0; i < movies.size(); i++)
		std::cout << movies[i].GetTitle() << "\n";*/

	 //a.RecommendInitialMovies(users[2]);

	 /*std::vector<Recommandation> r = Database::GetInstance()->SelectUserRecommandation(users[0]);


	 for (int i = 0; i < r.size(); i++)
	 {

	 }
	*/

	/*User user("Name1", "Password1", "10.10.2010", "Female");

	Database::GetInstance()->InsertElement(user);*/

	/*Movies movie("Movie", "Adolf", "Stalin", "URSS", "10.07.2002", 1988, 5, 120, "Nothing to say");*/

	//::GetInstance()->InsertElement(movie);

	/*auto movies = Database::GetInstance()->GetStorage()->get_all<Movies>();

	for (int i = 0; i < movies.size(); i++)
	{
		std::cout << movies[i].GetTitle();
	}*/

	//std::cout << "A";


	/*Actor actor(1, "FullName");

	Database::GetInstance()->InsertElement(actor);*/

	//db.m_storage.insert(user);

	/*std::string username, password;

	std::cout << "Login: \n";

	std::cout << "Enter username: ";
	std::cin >> username;
	std::cout << "\n";
	std::cout << "Enter password: ";
	std::cin >> password;
	std::cout << "\n";

	Login firstLog(username, password);*/
	//SignUp();

	//Application a(5);
	

	/*Movies movie("Movie", "Stalin", "Adolf", 1933, "Deutschland", 5, 120);
	db.m_storage.insert(movie);*/

	//std::cout << "Enter movie: \n";
	//std::string movieName;
	//std::cin >> movieName;

	//Application application;
	//application.ShowMovie(movieName);

	//User user("Marcel", "Password2", "10.10.2010", "Female");
	//Database::GetInstance()->InsertElement(user);
	//std::string username, password;

	//std::cout << "Login: \n";

	//std::cout << "Enter username: ";
	//std::cin >> username;
	//std::cout << "\n";
	//std::cout << "Enter password: ";
	//std::cin >> password;
	//std::cout << "\n";

	//Login firstLog(username, password);

	//SignUp();
	//Database::GetInstance()->PopulateMovies("netflix_titles.csv");
	//Application a;
	//a.RecommendMovies();
	//a.SearchMovie("taruto");
	/*auto v = Database::GetInstance()->SelectUserWatchedList(5);
	for (auto& i : v)
		std::cout << *i.GetMoviesID();*/
	
	//Database::GetInstance()->InsertElement(User("Marcel", "Password2", "10.11.2001", "Female"));
    //Database::GetInstance()->PopulateMovies("netflix_titles.csv");
	//Database::GetInstance()->PopulateGenres();
}