#include <exception>
using namespace std;

#include "../SatelliteLauncher.h"
#include "../Starlink.h"

SatelliteLauncher::SatelliteLauncher() {
	this->_successor = NULL;
}

void SatelliteLauncher::handleRequest() {
	if (this->_successor == NULL)
	{
		return;
	}
	else
	{
		this->_successor->handleRequest();
		delete this->_successor;
		this->_successor = NULL;
		return;
	}
}

void SatelliteLauncher::add(SatelliteLauncher* satellite) {
	if (this->_successor != NULL){
		this->_successor->add(satellite);
	}
	else
	{
		this->_successor = satellite;
	}
}

int SatelliteLauncher::count() {
	if (this->_successor == NULL) {
		return 1;
	}
	return 1 + this->_successor->count();
}