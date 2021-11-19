#include <exception>
using namespace std;

#ifndef __Aggregate_h__
#define __Aggregate_h__

// #include "Caretaker.h"
// #include "RocketMemento.h"
// #include "Iterator.h"

class Caretaker;
class RocketMemento;
class Iterator;
class Aggregate;

class Aggregate
{
	public: Caretaker* _unnamed_Caretaker_;
	public: RocketMemento* _unnamed_RocketMemento_;

	public: virtual void add(RocketMemento* aR) = 0;

	public: virtual void remove(RocketMemento* aR) = 0;

	public: virtual Iterator* createIterator() = 0;
};

#endif
