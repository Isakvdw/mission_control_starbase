#include <exception>
using namespace std;

#include "SatelliteFactory.h"
#include "SatelliteLauncher.h"
#include "Factory.h" 

SatelliteFactory::SatelliteFactory(const SatelliteFactory& obj) {

}

SatelliteLauncher* SatelliteFactory::createComponent() {
	return new SatelliteLauncher();
}

