#include <exception>
using namespace std;

#ifndef __SatelliteFactory_h__
#define __SatelliteFactory_h__

// #include "SatelliteLauncher.h"
#include "Factory.h"

class SatelliteLauncher;
// class Factory;
class SatelliteFactory; 

class SatelliteFactory: public Factory
{
	public: 
		SatelliteFactory(const SatelliteFactory& obj);
		SatelliteLauncher* createComponent();
};

#endif
