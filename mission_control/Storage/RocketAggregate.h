#include <exception>
#include <vector>
using namespace std;

#ifndef __RocketAggregate_h__
#define __RocketAggregate_h__

#include "RocketMemento.h"
#include "RocketIterator.h"
#include "Iterator.h"
#include "Aggregate.h"

class RocketAggregate : public Aggregate
{
private:
	vector<RocketMemento *> _mementos;

public:
	RocketIterator *rocket_iterator;
	void add(RocketMemento *aR);
	void remove(RocketMemento *aR);
	Iterator *createIterator();
};

#endif
