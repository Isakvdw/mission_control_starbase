#include <exception>
#include <vector>
using namespace std;

#include "Booster.h"
#include "Propulsion.h"

void Booster::add(Propulsion* aP) {
	throw "Not yet implemented";
}

void Booster::remove(Propulsion* aP) {
	throw "Not yet implemented";
}

int Booster::getLOXfuelLevel() {
	return this->_lOXfuelLevel;
}

void Booster::setLOXfuelLevel(int aLOXfuelLevel) {
	this->_lOXfuelLevel = aLOXfuelLevel;
}

int Booster::getRP1fuelLevel() {
	return this->_rP1fuelLevel;
}

void Booster::setRP1fuelLevel(int aRP1fuelLevel) {
	this->_rP1fuelLevel = aRP1fuelLevel;
}

void Booster::operation() {
	throw "Not yet implemented";
}

