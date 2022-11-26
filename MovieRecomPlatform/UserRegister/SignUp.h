#pragma once

#ifdef SIGNUP_EXPORTS
#define SIGNUP_API __declspec(dllexport)
#else 
#define SIGNUP_API __declspec(dllimport)
#endif // SIGNUP_EXPORTS

class SIGNUP_API SignUp
{
};
 