#ifndef _DEBUG_H_
#define _DEBUG_H_

#define DEBUG	1

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// print out two values
inline void debugMessage(const string m, const double a, const double b)
{
	if(DEBUG)
		printf(">>>DEBUG: %s = %Lf,%Lf\n", m.c_str(), a, b);
}

// print out a single value
inline void debugMessage(const string m, const double a)
{
	if(DEBUG)
		printf(">>>DEBUG: %s = %Lf\n", m.c_str(), a);
}

// print out error with value
inline void debugError(const string m, const string n, const double a)
{
	if(DEBUG)
		printf("###ERROR: %s : %s = %Lf\n", m.c_str(), n.c_str(), a);
}

#endif