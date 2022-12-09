#include "Recommandation.h"

Recommandation::Recommandation(std::unique_ptr<int> userId, std::unique_ptr<int> movieId) :
    m_userId{ std::move(userId) },
    m_movieId{ std::move(movieId) }
{}

const std::unique_ptr<int>& Recommandation::GetUserID() const
{
    return m_userId;
}

const std::unique_ptr<int>& Recommandation::GetMoviesID() const
{
    return m_movieId;
}

void Recommandation::SetUserID(std::unique_ptr<int> userId)
{
    m_userId = std::move(userId);
}

void Recommandation::SetMoviesID(std::unique_ptr<int> movieId)
{
    m_movieId = std::move(movieId);
}
