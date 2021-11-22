#include <exception>
using namespace std;

#ifndef __BuildS_h__
#define __BuildS_h__

#include "State.h"

class BuildS: public State
{
	public: 
		void changeState(Rocket* aR);
};

#endif