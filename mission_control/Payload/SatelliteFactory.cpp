#include <exception>
using namespace std;

#include "SatelliteFactory.h" 

/**
 * @brief Construct a new SatelliteFactory::SatelliteFactory object
 * @details Creates normal SatelliteFactory object used to construct
 * 			other Satellites.
 */
SatelliteFactory::SatelliteFactory() {
	
}

/**
 * @brief Construct a new SatelliteFactory::SatelliteFactory object
 * @details Copy constructor used to copy existing SatelliteFactories
 * 			Simply creates another instance.
 * @param obj 
 */
SatelliteFactory::SatelliteFactory(const SatelliteFactory& obj) {

}

/**
 * @brief Factory makes new satellite for user.
 * @details Used to create satellites on demand for use.
 * 			Creates a satellite and returns it to user.
 * @return SatelliteLauncher* 
 */
SatelliteLauncher* SatelliteFactory::createComponent() {
	SatelliteLauncher * Sat = new Satellite();
	return Sat;
}

