#include "User.h"
#include <sqlite_orm/sqlite_orm.h>

void CreateDatabase()
{
	using namespace sqlite_orm;

	auto storage = make_storage("db.sqlite",
		make_table("Users",
			make_column("id", &User::m_userId, autoincrement(), primary_key()),
			make_column("username", &User::m_username),
			make_column("password", &User::m_password)));

	storage.sync_schema(true);
}

int main()
{
	CreateDatabase();

}