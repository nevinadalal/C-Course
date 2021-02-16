#include <exception>

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

using namespace std;

class FullStackException : public exception
{
	const char * what () const throw ()
    {
    	return "The stack is full";
    }
};

class EmptyStackException : public exception
{
	const char * what () const throw ()
    {
    	return "The stack is empty";
    }
};

#endif // EXCEPTIONS_H