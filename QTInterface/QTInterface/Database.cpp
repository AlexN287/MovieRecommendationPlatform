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

Movies Database::SelectMovieById(const int& movieId)
{
	auto movies = instance->GetElements<Movies>();

	for (int i = 0; i < movies.size(); i++)
		if (movies[i].GetMoviesID() == movieId)
			return movies[i];
}

 Movies Database::SelectMovieByName(const std::string& movieName)
 {
	 auto movies = instance->GetElements<Movies>();

	 for (int i = 0; i < movies.size(); i++)
		 if (movies[i].GetTitle() == movieName)
			 return movies[i];
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

std::vector<std::string> splitComma(const std::string& str, const std::string& delim)
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

void Database::PopulateGenres()
{
	auto movies = Database::GetInstance()->GetElements<Movies>();
	std::string delim = ",";
	std::set<std::string> genres;


	for (int i = 0; i < movies.size(); i++)
	{
		std::vector<std::string> current = splitComma(movies[i].GetGenres(), delim);
		for (int j = 0; j < current.size(); j++)
		{

			std::cout << current[j] << "\n";
			genres.insert(current[j]);

		}
	}

	for (auto& it : genres)
	{
		Database::GetInstance()->InsertElement(Genres(it));
	}

}

void Database::PopulateMovies(const std::string& fileName)
{
	std::ifstream in(fileName);
	std::string str;
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


