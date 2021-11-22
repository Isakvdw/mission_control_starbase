#include <exception>
using namespace std;

#ifndef __ActiveLaunchS_h__
#define __ActiveLaunchS_h__

#include "State.h"

class Rocket;

class ActiveLaunchS: public State
{
	public: 
		void changeState(Rocket* aR);
};

#endif