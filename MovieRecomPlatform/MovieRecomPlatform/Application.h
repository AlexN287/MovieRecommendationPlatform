#pragma once
#include"Movies.h"

class Application
{
	enum class SearchStatus
	{
		Found,
		NotFound
	};

public:
	Application() = default;
	Movies SearchMovie();
	void ShowMovie();
};

