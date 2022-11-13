#include "User.h"
#include <sqlite_orm/sqlite_orm.h>
#include "Genres.h"
#include "Movies.h"

void CreateDatabase()
{
	using namespace sqlite_orm;

	auto storage = make_storage("db.sqlite",
		make_table("Users",
			make_column("id", &User::SetUserId, &User::GetUserId, autoincrement(), primary_key()),
			make_column("username", &User::SetUsername, &User::GetUsername),
			make_column("password", &User::SetPassword, &User::GetPassword)),
		make_table("Movies",
			make_column("moviesId", &Movies::SetMoviesID, &Movies::GetMoviesID, autoincrement(), primary_key()),
			make_column("type", &Movies::SetType, &Movies::GetType),
			make_column("title", &Movies::SetTitle, &Movies::GetTitle),
			make_column("director", &Movies::SetDirector, &Movies::GetDirector),
			make_column("releaseYear", &Movies::SetReleaseYear, &Movies::GetReleaseYear),
			make_column("cast", &Movies::SetCast, &Movies::GetCast),
			make_column("country", &Movies::SetCountry, &Movies::GetCountry),
			make_column("rating", &Movies::SetRating, &Movies::GetRating),
			make_column("duration", &Movies::SetDuration, &Movies::GetDuration)),
		make_table("Genres",
			make_column("genreId", &Genres::SetGenreId, &Genres::GetGenreId, autoincrement(), primary_key()),
			make_column("name", &Genres::SetName, &Genres::GetName))
		);

	storage.sync_schema(true);
}

int main()
{
	CreateDatabase();
	return 0;
}