#include <exception>
using namespace std;

#ifndef __Aggregate_h__
#define __Aggregate_h__

class Iterator;

#include "RocketMemento.h"

class Aggregate
{
public:
	// Caretaker *caretaker;
	RocketMemento *rocketMemento;
	virtual void add(RocketMemento *aR) = 0;
	virtual void remove(RocketMemento *aR) = 0;
	virtual Iterator *createIterator() = 0;
};

#endif
