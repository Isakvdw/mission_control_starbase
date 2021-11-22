#include <exception>
using namespace std;

#include "SatelliteLauncher.h"
#include "Starlink.h"

SatelliteLauncher::SatelliteLauncher() {
	this->_successor = NULL;
}

void SatelliteLauncher::handleRequest(SatelliteLauncher* prev) {
	throw "Not yet implemented"; 
}

void SatelliteLauncher::add(SatelliteLauncher* satellite) {
	if (this->_successor != NULL){
		this->_successor->add(satellite);
	}
	this->_successor = satellite;
}

int SatelliteLauncher::count() {
	if (this->_successor == NULL) {
		return 1;
	}
	return 1 + this->_successor->count();
}