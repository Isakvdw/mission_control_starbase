#include <exception>
using namespace std;

#include "SatelliteLauncher.h"

/**
 * @brief Construct a new Satellite Launcher:: Satellite Launcher object
 * 
 */
SatelliteLauncher::SatelliteLauncher() {
	this->_successor = NULL;
}

/**
 * @brief Destroy the Satellite Launcher:: Satellite Launcher object
 * 
 */
SatelliteLauncher::~SatelliteLauncher() {
	if (this->_successor != NULL)
	{
		delete this->_successor;
	}
	this->_successor = NULL;
}

/**
 * @brief SatelliteLauncher goes down the chain of Satellites.
 * Once it reaches the end they detach and delete. 
 * Simulates the satellites being ejected into orbit.
 *
 */
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

/**
 * @brief Adds a satellite to the chain.
 * 
 * @param satellite 
 */
void SatelliteLauncher::add(SatelliteLauncher* satellite) {
	if (this->_successor != NULL){
		this->_successor->add(satellite);
	}
	else
	{
		this->_successor = satellite;
	}
}

/**
 * @brief Counts all satellites in the chain.
 * 
 * @return int 
 */
int SatelliteLauncher::count() {
	if (this->_successor == NULL) {
		return 1;
	}
	return 1 + this->_successor->count();
}