#include <exception>
#include <string>
using namespace std;

#include "Builder.h"

Rocket::RocketType Builder::getRocketType() {
	return this->_rocketType;
}

void Builder::setRocketType(Rocket::RocketType aRocketType) {
	this->_rocketType = aRocketType;
}

