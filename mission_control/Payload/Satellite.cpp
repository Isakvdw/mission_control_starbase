#include <exception>
using namespace std;

#include "Satellite.h"
// #include "SatelliteLauncher.h" 

/**
 * @brief Construct a new Satellite:: Satellite object
 * 
 */
Satellite::Satellite() {
	
}

/**
 * @brief Construct a new Satellite:: Satellite object
 * 
 * @param obj 
 */
Satellite::Satellite(const Satellite& obj) {
	
}

/**
 * @brief Clones satellite and returns new one.
 * 
 * @return Satellite* 
 */
Satellite* Satellite::clone() {
	return new Satellite(*this);
}

