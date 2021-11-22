#include <exception>
#include <vector>
using namespace std;

#include "RocketIterator.h"

RocketMemento *RocketIterator::next()
{
	++current;
	return (*_curr)[current];
}

bool RocketIterator::end()
{
	return current == _curr->size() - 1;
}

RocketMemento *RocketIterator::start()
{
	current = 0;
	return (*_curr)[current];
}

RocketMemento *RocketIterator::getCurr()
{
	return (*_curr)[current];
}

RocketIterator::RocketIterator(RocketAggregate *aRAgg) : rocketAggregate(aRAgg), current(0)
{
}
