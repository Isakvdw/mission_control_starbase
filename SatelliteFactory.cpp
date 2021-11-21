#include <exception>
using namespace std;

#include "SatelliteFactory.h"
#include "SatelliteLauncher.h"
#include "Factory.h"

SatelliteLauncher::SatelliteLauncher(const SatelliteLauncher& obj) {}

SatelliteLauncher* SatelliteFactory::createComponent() {
	return new SatelliteLauncher();
}

