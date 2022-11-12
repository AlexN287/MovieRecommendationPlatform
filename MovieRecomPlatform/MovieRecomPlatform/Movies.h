#pragma once
#include<string>
#include<cstdint>

class Movies
{
private:
	int m_moviesId;
	std::string m_type;
	std::string m_title;
	std::string m_director;
	int m_releaseYear;
	std::string m_cast;
	std::string m_country;
	uint8_t m_rating;
	int m_duration;
};

