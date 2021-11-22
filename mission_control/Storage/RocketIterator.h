#include <exception>
#include <vector>
using namespace std;

#ifndef __RocketIterator_h__
#define __RocketIterator_h__

#include "Iterator.h"
// #include "RocketAggregate.h"
#include "RocketMemento.h"

class RocketAggregate;

class RocketIterator : public Iterator
{
private:
	vector<RocketMemento *> *_curr;
	int current;

public:
	RocketAggregate *rocketAggregate;
	// Builder *rocketBuilder;
	RocketMemento *next();
	bool end();
	RocketMemento *start();
	RocketMemento *getCurr();
	RocketIterator(RocketAggregate *aRAgg);
};

#endif
