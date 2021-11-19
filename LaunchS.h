#include <exception>
using namespace std;

#ifndef __LaunchS_h__
#define __LaunchS_h__

// #include "Rocket.h"
#include "State.h"

class Rocket;
// class State;
class LaunchS;

class LaunchS: public State
{

	public: void changeState(Rocket* aR);
};

#endif
