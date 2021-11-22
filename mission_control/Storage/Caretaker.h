#include <exception>
using namespace std;

#ifndef __Caretaker_h__
#define __Caretaker_h__

// #include "../Aggregate.h"
// #include "../Iterator.h"
// #include "../RocketMemento.h"

class Aggregate;
class Iterator;
class RocketMemento;
class Caretaker;

class Caretaker
{
	private: Aggregate* _mementos;
	public: Iterator* _unnamed_Iterator_;
	public: RocketMemento* _unnamed_RocketMemento_;
	public: Aggregate* _unnamed_Aggregate_;

	public: Iterator* createIterator();
};

#endif
