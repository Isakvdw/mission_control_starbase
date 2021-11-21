#include <exception>
#include <string>
#include <iostream>
using namespace std;

#include "FuelObserver.h"
#include "Booster.h"
#include "Observer.h"

void FuelObserver::update() {
	_lOXfuelState = _concreteBooster->getLOXfuelLevel();
	_rP1fuelState = _concreteBooster->getRP1fuelLevel();
	assessFuel();
}

void FuelObserver::assessFuel() {
	cout << "--------------------------------------------------------------------" << endl;
	cout << "Booster (LOX, RP1) fuel levels at (" 
		<< _lOXfuelState << "," << _rP1fuelState << ")%" << endl;
	string lOXstate, rP1state;
	// Get descriptions for fuel levels
	lOXstate = fuelDescription(_lOXfuelState); 
	rP1state = fuelDescription(_rP1fuelState);
	cout << "\tLOX level: " << lOXstate << endl;
	cout << "\tRP1 level: " << rP1state << endl;
	cout << "--------------------------------------------------------------------" << endl;
}

void FuelObserver::setSubjectBooster(Booster* aBooster) {
	_concreteBooster = aBooster;
}

string FuelObserver::fuelDescription(int level) {
	if (level >= 100) return "FULL";
	if (level <= 0) return "EMPTY";
	if (level >= 80) return "HIGH";
	if (level >= 35) return "OK";
	return "LOW";
}