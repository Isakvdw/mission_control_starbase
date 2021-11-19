#include <exception>
#include <vector>
using namespace std;

#ifndef __Propulsion_h__
#define __Propulsion_h__

// #include "Observer.h"
// #include "Rocket.h"
// #include "Booster.h"

class Observer;
class Rocket;
// class Booster;
class Propulsion;

class Propulsion
{
	private: vector<Observer*> _observerList;
	public: Rocket* _unnamed_Rocket_;
	public: Booster* _unnamed_Booster_;
	public: Observer* _unnamed_Observer_;

	public: virtual void add(Propulsion* aP) = 0;

	public: virtual void remove(Propulsion* aP) = 0;

	public: virtual void operation() = 0;

	public: void attach(Observer* aO);

	public: void detach(Observer* aO);

	public: void notify();
};

#endif
