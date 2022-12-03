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

std::vector<std::string> split(const std::string& str, const std::string& delim)
{
	std::vector<std::string> result;
	size_t startIndex = 0;

	for (size_t found = str.find(delim); found != std::string::npos; found = str.find(delim, startIndex))
	{
		result.emplace_back(str.begin() + startIndex, str.begin() + found);
		startIndex = found + delim.size();
	}
	if (startIndex != str.size())
		result.emplace_back(str.begin() + startIndex, str.end());
	return result;
}

void Database::PopulateMovies(const std::string& fileName)
{
	std::ifstream in(fileName);

	std::string str;

	const std::string delim{ "," };
	std::vector<Movies> movies;

	while (getline(in, str))
	{
		
		std::vector<std::string> result = split(str, delim);

		//std::cout << result[0] << " " << result[3] << " " << result[result.size() - 1] << std::endl;
		movies.emplace_back(Movies( result[1], result[2], result[3], result[4] ,result[5], result[6],
			std::stoi(result[7]), result[8], std::stoi(result[9]), result[10],
			result[11]) );

	}
	//m_db.insert_range(books.begin(), books.end());
	for (int i = 0; i < movies.size(); i++)
	{
		Database::GetInstance()->InsertElement(movies[i]);
	}
	
}

void Database::PopulateActors(const std::string& fileName)
{
}

