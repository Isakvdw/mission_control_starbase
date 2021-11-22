#include <exception>
using namespace std;

#ifndef __SatelliteFactory_h__
#define __SatelliteFactory_h__ 

#include "Factory.h"
#include "Satellite.h"

class SatelliteFactory: public Factory
{
	public: 
		SatelliteFactory();
		SatelliteFactory(const SatelliteFactory& obj);
		SatelliteLauncher* createComponent();
};

#endif
