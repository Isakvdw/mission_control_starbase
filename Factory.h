#include <exception>
using namespace std;

#ifndef __Factory_h__
#define __Factory_h__

// #include "SatelliteLauncher.h"

class SatelliteLauncher;
class Factory;

class Factory 
{
	public: 
		virtual SatelliteLauncher* createComponent() = 0;
};

#endif
