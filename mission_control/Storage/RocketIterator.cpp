#include <exception>
#include <vector>
using namespace std;

#include "RocketIterator.h"

RocketMemento *RocketIterator::next()
{
	++current;
	return (*_curr)[current];
}

bool RocketIterator::isEnd()
{
	return current == _curr->size();
}

RocketMemento *RocketIterator::End()
{
	current = _curr->size();
	return (*_curr)[current];
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
