#include <exception>
using namespace std;

#include "../SatelliteFactory.h"
#include "../SatelliteLauncher.h"
#include "../Satellite.h"
#include "../Factory.h" 

/**
 * @brief Construct a new Satellite Factory:: Satellite Factory object
 * 
 */
SatelliteFactory::SatelliteFactory() {
	
}

/**
 * @brief Construct a new Satellite Factory:: Satellite Factory object
 * 
 * @param obj 
 */
SatelliteFactory::SatelliteFactory(const SatelliteFactory& obj) {

}

/**
 * @brief Factory makes new satellite for user.
 * 
 * @return SatelliteLauncher* 
 */
SatelliteLauncher* SatelliteFactory::createComponent() {
	SatelliteLauncher * Sat = new Satellite();
	return Sat;
}

