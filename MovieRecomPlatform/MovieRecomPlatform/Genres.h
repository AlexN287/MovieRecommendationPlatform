#pragma once
#include <string>
class Genres
{
private:
	int m_genreId;
	std::string m_name;

public:
	Genres() = default;
	Genres(std::string name);
	Genres(const Genres& genres) = default;
	bool operator==(const Genres& genres);
	~Genres() = default;

	int GetGenreId() const;
	void SetGenreId(int genreId);
	std::string GetName() const;
	void SetName(std::string name);
};

