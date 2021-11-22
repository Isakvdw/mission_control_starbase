
#ifndef __RocketMemento_h__
#define __RocketMemento_h__
#include <string>
#include <iostream>

using namespace std;

#include "Caretaker.h"
#include "Aggregate.h"
class RocketMemento
{
private:
	string _rocket_state;

public:
	RocketMemento(string s);
	Caretaker *caretaker;
	Aggregate *rocketAggregate;
};

#endif
