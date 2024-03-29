#pragma once
#include "User.h"
#include <sqlite_orm/sqlite_orm.h>
#include "Genres.h"
#include "Movies.h"
#include "Wishlist.h"
#include "Actor.h"
#include "MovieActor.h"
#include "UserRating.h"
#include "WatchedList.h"
#include "LikedGenre.h"
#include "MovieGenre.h"
#include "User.h"
#include "LikedActors.h"
#include "Recommandation.h"
#include <memory>
#include<fstream>
#include<iostream>
#include <set>

inline auto CreateDatabase()
{
	using namespace sqlite_orm;

	return make_storage("db.sqlite",
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
			make_column("cast", &Movies::SetCast, &Movies::GetCast),
			make_column("country", &Movies::SetCountry, &Movies::GetCountry),
			make_column("dateAdded", &Movies::SetDateAdded, &Movies::GetDateAdded),
			make_column("releaseYear", &Movies::SetReleaseYear, &Movies::GetReleaseYear),
			make_column("rating", &Movies::SetRating, &Movies::GetRating),
			make_column("duration", &Movies::SetDuration, &Movies::GetDuration),
			make_column("genres", &Movies::SetGenres, &Movies::GetGenres),
		    make_column("description", &Movies::SetDescription, &Movies::GetDescription)),
		make_table("Genres",
			make_column("genreId", &Genres::SetGenreId, &Genres::GetGenreId, autoincrement(), primary_key()),
			make_column("name", &Genres::SetName, &Genres::GetName)),
		make_table("Wishlist",
			make_column("wishlistId", &Wishlist::SetWishlistID, &Wishlist::GetWishlistID, autoincrement(), primary_key()),
			make_column("userId", &Wishlist::GetUserID, &Wishlist::SetUserID),
			make_column("moviesId", &Wishlist::GetMoviesID, &Wishlist::SetMoviesID),
			//primary_key(&Wishlist::GetUserID, &Wishlist::SetUserID, &Wishlist::GetMoviesID, &Wishlist::SetMoviesID),
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
			make_column("userRatingId", &UserRating::SetUserRatingId, &UserRating::GetUserRatingId, autoincrement(), primary_key()),
			make_column("userId", &UserRating::SetUserId, &UserRating::GetUserId),
			make_column("movieId", &UserRating::SetMovieId, &UserRating::GetMovieId),
			make_column("rating", &UserRating::SetRating, &UserRating::GetRating),
			foreign_key(&UserRating::SetUserId).references(&User::GetUserId),
			foreign_key(&UserRating::SetMovieId).references(&Movies::GetMoviesID)),
			//primary_key(&UserRating::SetUserId, &UserRating::GetUserId, &UserRating::SetMovieId, &UserRating::GetMovieId)),
		make_table("WatchedList",
			make_column("userId", &WatchedList::GetUserID, &WatchedList::SetUserID),
			make_column("moviesId", &WatchedList::GetMoviesID, &WatchedList::SetMoviesID),
			//primary_key(&WatchedList::GetUserID, &WatchedList::SetUserID, &WatchedList::GetMoviesID, &WatchedList::SetMoviesID),
			foreign_key(&WatchedList::SetUserID).references(&User::GetUserId),
			foreign_key(&WatchedList::SetMoviesID).references(&Movies::GetMoviesID)),
		make_table("LikedGenre",
			make_column("userId", &LikedGenre::GetUserID, &LikedGenre::SetUserID),
			make_column("genre", &LikedGenre::GetGenre, &LikedGenre::SetGenre),
			foreign_key(&LikedGenre::SetUserID).references(&User::GetUserId)),
		make_table("MovieGenre",
			make_column("genreId", &MovieGenre::GetGenreId, &MovieGenre::SetGenreId),
			make_column("moviesId", &MovieGenre::GetMoviesId, &MovieGenre::SetMoviesId),
			primary_key(&MovieGenre::GetGenreId, &MovieGenre::SetGenreId, &MovieGenre::GetMoviesId, &MovieGenre::SetMoviesId),
			foreign_key(&MovieGenre::SetGenreId).references(&Genres::GetGenreId),
			foreign_key(&MovieGenre::SetMoviesId).references(&Movies::GetMoviesID)),
		make_table("LikedActors",
			make_column("userId", &LikedActors::GetUserId, &LikedActors::SetUserId),
			make_column("actor", &LikedActors::GetActor, &LikedActors::SetActor),
			foreign_key(&LikedActors::SetUserId).references(&User::GetUserId)),
		make_table("Recommandation",
			make_column("recommandationId", &Recommandation::SetRecommandationID, &Recommandation::GetRecommandationID, autoincrement(), primary_key()),
			make_column("userId", &Recommandation::GetUserID, &Recommandation::SetUserID),
			make_column("movieId", &Recommandation::GetMovieID, &Recommandation::SetMovieID),
			//primary_key(&Recommandation::GetUserID, &Recommandation::GetUserID, &Recommandation::GetMovieID, &Recommandation::GetMovieID),
			foreign_key(&Recommandation::SetUserID).references(&User::GetUserId),
			foreign_key(&Recommandation::SetMovieID).references(&Movies::GetMoviesID))
	);
}

using Storage = decltype(CreateDatabase());
class Database
{
	std::unique_ptr<Storage> m_storage;
	Database();
	void SyncSchema();
	static Database* instance;
public:
	/*const std::unique_ptr<Storage>& getStorage() {
		return m_storage;
	}*/

	Database(Database&) = delete;
	void operator=(const Database&) = delete;
	static Database* GetInstance();
	static void PopulateMovies(const std::string& fileName);
	static void PopulateGenres();

	template<class T>
	static void InsertElement(const T& element)
	{
		instance->m_storage->insert(element);
	}

	template<class T>
	static void RemoveElement(int elementId)
	{
		instance->m_storage->remove<T>(elementId);
	}

	template<class T>
	static void ReplaceElement(T element)
	{
		instance->m_storage->replace(element);
	}

	template<class T>
	static auto GetElements()
	{
		return instance->m_storage->get_all<T>();
	}

	static auto SelectUserWatchedList(const int& userId)
	{
		using namespace sqlite_orm;
		namespace sql = sqlite_orm;
		return instance->m_storage->get_all<WatchedList>(where(c(&WatchedList::GetUserID) == userId));
	}

	static auto SelectUserWishList(const int& userId)
	{
		using namespace sqlite_orm;
		namespace sql = sqlite_orm;
		return instance->m_storage->get_all<Wishlist>(where(c(&Wishlist::GetUserID) == userId));
	}

	static auto SelectUserRating(const int& userId)
	{
		using namespace sqlite_orm;
		namespace sql = sqlite_orm;
		return instance->m_storage->get_all<UserRating>(where(c(&UserRating::GetUserId) == userId));
	}

	 static auto SelectUserLikedGenres(const int& userId)
	{
		using namespace sqlite_orm;
		namespace sql = sqlite_orm;
		return instance->m_storage->get_all<LikedGenre>(where(c(&LikedGenre::GetUserID) == userId));

		/*auto list = instance->GetElements<LikedGenre>();
		std::vector<LikedGenre> list2;

		for (int i = 0; i < list.size(); i++)
		{
			int id = *list[i].GetUserID();
			if (id == userId)
				list2.push_back(list[i]);
		}

		return list2;*/
	}

	Movies SelectMovieById(const int& movieId);
	
	static auto SelectUserRecommandation(const int& userId)
	{
		using namespace sqlite_orm;
		namespace sql = sqlite_orm;
		return instance->m_storage->get_all<Recommandation>(where(c(&Recommandation::GetUserID) == userId));
	}
};

