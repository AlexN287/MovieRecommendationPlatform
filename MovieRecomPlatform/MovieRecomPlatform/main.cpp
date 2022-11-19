#include "User.h"
#include <sqlite_orm/sqlite_orm.h>
#include "Genres.h"
#include "Movies.h"
#include "Wishlist.h"
#include "Actor.h"
#include "MovieActor.h"
#include "UserRating.h"

void CreateDatabase()
{
	using namespace sqlite_orm;

	auto storage = make_storage("db.sqlite",
		make_table("Users",
			make_column("id", &User::SetUserId, &User::GetUserId, autoincrement(), primary_key()),
			make_column("username", &User::SetUsername, &User::GetUsername),
			make_column("password", &User::SetPassword, &User::GetPassword),
			make_column("birthdate", &User::SetBirthdate, &User::GetBirthdate),
			make_column("gender", &User::SetGender, &User::GetGender)),
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
			make_column("name", &Genres::SetName, &Genres::GetName)),
		make_table("Wishlist",
			make_column("userId", &Wishlist::GetUserID, &Wishlist::SetUserID),
			make_column("moviesId", &Wishlist::GetMoviesID, &Wishlist::SetMoviesID),
			primary_key(&Wishlist::GetUserID, &Wishlist::SetUserID, &Wishlist::GetMoviesID, &Wishlist::SetMoviesID),
			foreign_key(&Wishlist::SetUserID).references(&User::GetUserId),
			foreign_key(&Wishlist::SetMoviesID).references(&Movies::GetMoviesID)),
		make_table("Actors",
			make_column("actorId", &Actor::SetActorId, &Actor::GetActorId, primary_key()),
			make_column("fullName", &Actor::SetFullName, &Actor::GetFullName)),
		make_table("MovieActor",
			make_column("actorId", &MovieActor::SetActorId, &MovieActor::GetActorId),
			make_column("movieId", &MovieActor::SetMoviesId, &MovieActor::GetMoviesId),
			foreign_key(&MovieActor::SetActorId).references(&Actor::GetActorId),
			foreign_key(&MovieActor::SetMoviesId).references(&Movies::GetMoviesID),
			primary_key(&MovieActor::SetActorId, &MovieActor::GetActorId, &MovieActor::SetMoviesId, &MovieActor::GetMoviesId)),
		make_table("UserRating",
			make_column("userId", &UserRating::SetUserId, &UserRating::GetUserId),
			make_column("movieId", &UserRating::SetMovieId, &UserRating::GetMovieId),
			make_column("rating", &UserRating::SetRating, &UserRating::GetRating),
			foreign_key(&UserRating::SetUserId).references(&User::GetUserId),
			foreign_key(&UserRating::SetMovieId).references(&Movies::GetMoviesID),
			primary_key(&UserRating::SetUserId, &UserRating::GetUserId, &UserRating::SetMovieId, &UserRating::GetMovieId))
		);

	storage.sync_schema(true);
}

int main()
{
	CreateDatabase();
	return 0;
}