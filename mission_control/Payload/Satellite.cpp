#include <exception>
using namespace std;

#include "Satellite.h"

/**
 * @brief Construct a new Satellite::Satellite object 
 * @details Creates normal Satellite.
 */
Satellite::Satellite() {
	
}

/**
 * @brief Construct a new Satellite::Satellite object
 * @details Copy constructor to make copied Satellites
 * 			from existing Satellites.
 * @param obj 
 */
Satellite::Satellite(const Satellite& obj) {
	
}

/**
 * @brief Clones satellite and returns new one.
 * @details Creates a cloned Satellite when a Satellite 
 * 			calls to clone itself.
 * @return Satellite* 
 */
Satellite* Satellite::clone() {
	return new Satellite(*this);
}

