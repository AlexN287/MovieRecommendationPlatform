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

std::vector<std::string> split(const std::string& s)
{
	std::vector<std::string> splitted;
	bool flag = false;
	splitted.push_back("");
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '"')
		{
			flag = flag ? false : true;
			continue;
		}

		if (s[i] == ',' && !flag)
			splitted.push_back("");
		else
			splitted[splitted.size() - 1] += s[i];
	}
	return splitted;
}

void Database::PopulateMovies(const std::string& fileName)
{
	std::ifstream in(fileName);

	std::string str;

	const std::string delim{ "," };
	std::vector<Movies> movies;
	std::getline(in,str);
	while (getline(in, str))
	{
		std::cout << str << "\n";
		
		std::vector<std::string> result = split(str);

		Database::GetInstance()->InsertElement(Movies(result[1], result[2], result[3], result[4], result[5], result[6],
			result[7], result[8], result[9], result[10], result[11]));
		
	}
}

void Database::PopulateActors(const std::string& fileName)
{
}

