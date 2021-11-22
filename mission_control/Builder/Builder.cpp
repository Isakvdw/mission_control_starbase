#include <exception>
#include <string>
using namespace std;

#include "Builder.h"
//#include "MissionControlStarbase.h" 	// Don't think needed
//#include "RocketIterator.h" 			// Don't think needed
//#include "Rocket.h"					// Don't think needed

Rocket* Builder::buildRocket() {
	throw "Not yet implemented";
}

string Builder::getRocketType() {
	return this->_rocketType;
}

void Builder::setRocketType(string aRocketType) {
	this->_rocketType = aRocketType;
}

