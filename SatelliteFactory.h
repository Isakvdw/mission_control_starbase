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
	SatelliteLauncher(const SatelliteLauncher& obj);
	public: SatelliteLauncher* createComponent();
};

#endif
