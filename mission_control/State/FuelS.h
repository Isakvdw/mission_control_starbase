#include <exception>
using namespace std;

#ifndef __FuelS_h__
#define __FuelS_h__

// #include "../Rocket.h"
#include "../State.h"

class Rocket;
// class State;
class FuelS;

class FuelS: public State
{

	public: void changeState(Rocket* aR);
};

#endif
