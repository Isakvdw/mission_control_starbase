#include <exception>
using namespace std;

#include "SatelliteFactory.h"
#include "SatelliteLauncher.h"
#include "Satellite.h"
#include "Factory.h" 

SatelliteFactory::SatelliteFactory() {
	
}

SatelliteFactory::SatelliteFactory(const SatelliteFactory& obj) {

}

SatelliteLauncher* SatelliteFactory::createComponent() {
	SatelliteLauncher * Sat = new Satellite();
	return Sat;
}

