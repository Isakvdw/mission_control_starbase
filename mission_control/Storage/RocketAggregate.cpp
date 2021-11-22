#include <exception>
#include <vector>
using namespace std;

#include "RocketAggregate.h"

void RocketAggregate::add(RocketMemento *aR)
{
	_mementos.push_back(aR);
}

void RocketAggregate::remove(RocketMemento *aR)
{
	for (int i = 0; i < _mementos.size(); i++)
	{
		if (_mementos[i] == aR)
		{
			_mementos[i] = _mementos[_mementos.size() - 1];
			_mementos.pop_back();
		}
	}
}

Iterator *RocketAggregate::createIterator()
{
	return new RocketIterator(&_mementos);
}
