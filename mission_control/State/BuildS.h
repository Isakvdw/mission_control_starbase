#include <exception>
using namespace std;

#ifndef __BuildS_h__
#define __BuildS_h__

// #include "Rocket.h"
#include "State.h"

class Rocket;
// class State;
class BuildS;

class BuildS: public State
{

	public: void changeState(Rocket* aR);
};

#endif
