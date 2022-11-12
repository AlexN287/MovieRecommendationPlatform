#pragma once
#include <string>
class Genres
{
private:
	int m_genreId;
	std::string m_name;

public:
	Genres(int genreId, std::string name);
	Genres(const Genres& genres) = default;
	~Genres() = default;

	int GetGenreId() const;
	void SetGenreId(int genreId);
	std::string GetName() const;
	void SetName(std::string name);
};

