#include <exception>
using namespace std;

#ifndef __Observer_h__
#define __Observer_h__

// #include "Propulsion.h"

class Propulsion;
class Observer;

class Observer
{
	public: Propulsion* _unnamed_Propulsion_;

	public: virtual void update() = 0;
};

#endif
