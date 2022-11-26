#include "Database.h"

Database::Database() {
	initialize();
}
void Database::initialize() {
	m_storage.sync_schema();
}