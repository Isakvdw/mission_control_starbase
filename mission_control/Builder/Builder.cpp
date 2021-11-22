#include <exception>
#include <string>
using namespace std;

#include "Builder.h"

string Builder::getRocketType() {
	return this->_rocketType;
}

void Builder::setRocketType(string aRocketType) {
	this->_rocketType = aRocketType;
}

