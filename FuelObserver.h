#include <exception>
#include <string>
using namespace std;

#ifndef __FuelObserver_h__
#define __FuelObserver_h__

// #include "Booster.h"
#include "Observer.h"

class Booster;
// class Observer;
class FuelObserver;

class FuelObserver: public Observer
{
	private: string _lOXfuelState;
	private: string _rP1fuelState;
	private: Booster* _concreteBooster;

	public: void update();
};

#endif
