
#ifndef __RocketMemento_h__
#define __RocketMemento_h__
#include <string>
#include <iostream>

using namespace std;

// #include "Caretaker.h"
//#include "Aggregate.h"

class Caretaker;
// class Aggregate;

class RocketMemento
{
private:
	string _rocket_state;

public:
	RocketMemento(string s);
	string getRocketState();
	Caretaker *caretaker;
	// Aggregate *rocketAggregate;
};

#endif
