#include <exception>
#include <vector>
using namespace std;

#include "Booster.h"

void Booster::add(Propulsion* aP) {
	_children.push_back(aP);
}

void Booster::remove(Propulsion* aP) {
	for (auto it = _children.begin(); it < _children.end(); it++) {
		if (*it == aP) {
			_children.erase(it);
			return;
		}
	}
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

