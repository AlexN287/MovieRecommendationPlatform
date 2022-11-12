#include "Movies.h"

Movies::Movies(int moviesId, std::string type, std::string title, std::string director, int releaseYear,
	std::string cast, std::string country, uint8_t rating, int duration) :
	m_moviesId{ moviesId },
	m_type{ type },
	m_title{ title },
	m_director{ director },
	m_releaseYear{ releaseYear },
	m_cast{ cast },
	m_country{ country },
	m_rating{ rating },
	m_duration{ duration }
{
}
