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
	return current == _curr->size();
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

RocketIterator::RocketIterator(vector<RocketMemento *> *c) : current(0)
{
	_curr = c;
}
