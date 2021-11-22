#include <exception>
using namespace std;

#ifndef __LaunchS_h__
#define __LaunchS_h__

#include "State.h"

class LaunchS: public State
{
	public: 
		void changeState(Rocket* aR);
};

#endif