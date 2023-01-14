#include "Genres.h"

Genres::Genres(std::string name) :
	m_genreId{ 0 },
	m_name{ name }
{
}

bool Genres::operator==(const Genres& genres)
{
	return this->m_genreId = genres.m_genreId;
}

int Genres::GetGenreId() const
{
	return m_genreId;
}

void Genres::SetGenreId(int genreId)
{
	m_genreId = genreId;
}

std::string Genres::GetName() const
{
	return m_name;
}

void Genres::SetName(std::string name)
{
	m_name = name;
}