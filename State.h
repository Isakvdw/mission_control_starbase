#include <exception>
using namespace std;

#ifndef __State_h__
#define __State_h__

// #include "Rocket.h"

class Rocket;
class State;

class State
{
	public: Rocket* _unnamed_Rocket_;

	public: virtual void changeState(Rocket* aR) = 0;
};

#endif
