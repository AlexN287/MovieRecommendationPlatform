#include "Recommandation.h"

Recommandation::Recommandation(std::unique_ptr<int> userId, std::unique_ptr<int> movieId) :
    m_userId{ std::move(userId) },
    m_movieId{ std::move(movieId) }
{}

Recommandation::Recommandation(const Recommandation & recommandation) :
    m_userId(std::make_unique<int>(*recommandation.m_userId)),
    m_movieId(std::make_unique<int>(*recommandation.m_movieId))
{

}

const std::unique_ptr<int>& Recommandation::GetUserID() const
{
    return m_userId;
}

const std::unique_ptr<int>& Recommandation::GetMovieID() const
{
    return m_movieId;
}

void Recommandation::SetUserID(std::unique_ptr<int> userId)
{
    m_userId = std::move(userId);
}

void Recommandation::SetMovieID(std::unique_ptr<int> movieId)
{
    m_movieId = std::move(movieId);
}
