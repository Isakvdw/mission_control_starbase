#include <exception>
#include <vector>
using namespace std;

#ifndef __RocketAggregate_h__
#define __RocketAggregate_h__

#include "RocketIterator.h"
#include "Aggregate.h"

class RocketAggregate : public Aggregate
{
private:
	vector<RocketMemento *> _mementos;

public:
	void add(RocketMemento *aR);
	void remove(RocketMemento *aR);
	Iterator *createIterator();
};

#endif
