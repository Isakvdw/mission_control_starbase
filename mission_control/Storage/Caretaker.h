#include <exception>
using namespace std;

#ifndef __Caretaker_h__
#define __Caretaker_h__

#include "Aggregate.h"
#include "Iterator.h"
#include "RocketMemento.h"

class Caretaker
{
private:
	Aggregate *_mementos;

public:
	Iterator *rocketIterator;
	RocketMemento *rocketMemento;
	Aggregate *rocketAggregate;
	Iterator *createIterator();
};

#endif
