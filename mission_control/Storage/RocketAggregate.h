#include <exception>
#include <vector>
using namespace std;

#ifndef __RocketAggregate_h__
#define __RocketAggregate_h__

// #include "../RocketMemento.h"
// #include "../RocketIterator.h"
// #include "../Iterator.h"
#include "../Aggregate.h"

class RocketMemento;
class RocketIterator;
class Iterator;
// class Aggregate;
class RocketAggregate;

class RocketAggregate: public Aggregate
{
	private: vector<RocketMemento*> _mementos;
	public: RocketIterator* _unnamed_RocketIterator_;

	public: void add(RocketMemento* aR);

	public: void remove(RocketMemento* aR);

	public: Iterator* createIterator();
};

#endif
