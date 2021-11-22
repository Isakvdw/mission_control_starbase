#include <exception>
#include <string>
using namespace std;

#include "Builder.h"
#include "MissionControlStarbase.h"
#include "RocketIterator.h"
#include "Rocket.h"

Rocket* Builder::buildRocket() {
	throw "Not yet implemented";
}

string Builder::getRocketType() {
	return this->_rocketType;
}

void Builder::setRocketType(string aRocketType) {
	this->_rocketType = aRocketType;
}

