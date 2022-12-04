#pragma once
#include <memory>
#include <string>

class LikedActors
{
private:
	std::unique_ptr<int> m_userId;
	std::string m_actor;
public:
	LikedActors() = default;
	LikedActors(std::unique_ptr<int> userId, std::string actor);
	~LikedActors() = default;

	std::string GetActor() const;
	const std::unique_ptr<int>& GetUserId() const;
	void SetActor(std::string actor);
	void SetUserId(std::unique_ptr<int> userId);
};

