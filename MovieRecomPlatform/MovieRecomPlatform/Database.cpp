#include "Database.h"

Database::Database() {
	m_storage = std::make_unique<Storage>(CreateDatabase());
	SyncSchema();
}
void Database::SyncSchema() {
	m_storage->sync_schema();
}

Database* Database::instance = nullptr;

Database* Database::GetInstance()
{
	if (instance == nullptr)
		instance = new Database();

	return instance;
}

void Database::PopulateActors(const std::string& fileName)
{
}
