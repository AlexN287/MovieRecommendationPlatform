#pragma once
#include<memory>

class MovieGenre
{
private:
	std::unique_ptr<int> m_genreId;
	std::unique_ptr<int> m_moviesId;

public:
	MovieGenre(std::unique_ptr<int> genreId, std::unique_ptr<int> moviesId);
	MovieGenre(const MovieGenre& movieGenre) = default;
	~MovieGenre() = default;

	const std::unique_ptr<int>& GetGenreId() const;
	void SetGenreId(std::unique_ptr<int> genreId);
	const std::unique_ptr<int>& GetMoviesId() const;
	void SetMoviesId(std::unique_ptr<int> moviesId);
};

