#include <exception>
using namespace std;

#ifndef __FuelS_h__
#define __FuelS_h__

#include "State.h"

class FuelS: public State
{

	public: void changeState(Rocket* aR);
};

#endif
