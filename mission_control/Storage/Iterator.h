#include <exception>
using namespace std;

#ifndef __Iterator_h__
#define __Iterator_h__

#include "Caretaker.h"
#include "RocketMemento.h"

class Iterator
{
public:
	virtual RocketMemento *next() = 0;
	virtual bool end() = 0;
	virtual RocketMemento *start() = 0;
	RocketMemento *getCurr();
};

#endif
