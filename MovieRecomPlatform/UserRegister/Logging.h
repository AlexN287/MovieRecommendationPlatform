#pragma once

#ifdef LOGGING_EXPORTS
#define LOGGING_API __declspec(dllexport)
#else 
#define LOGGING_API __declspec(dllimport)
#endif // LOGGING_EXPORTS

class LOGGING_API Logging
{
};

