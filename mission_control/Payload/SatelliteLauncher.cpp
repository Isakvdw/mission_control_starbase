#include <exception>
using namespace std;

#include "SatelliteLauncher.h" 

/**
 * @brief Construct a new SatelliteLauncher::SatelliteLauncher object
 * @details Parent Constructor for Satellite children.
 * 			Sets successor to NULL.
 */
SatelliteLauncher::SatelliteLauncher() {
	this->_successor = NULL;
}

/**
 * @brief Destroy the SatelliteLauncher::SatelliteLauncher object
 * @details Destructor used to delete successor objects.
 * 			Used for deletion when object my longer be used.
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
 * @details Once handleRequest() is called.
 * 			Starting from the head the list of Satellites is
 * 			traversed until the very end.
 * 			At the end through recursion the ends get deleted 
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
 * @details Adds a satellite to the current list of
 * 			satellites with use of recursion to find
 * 			end. Once the end is found, new satellite
 * 			is added to the end.
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
 * @details Through recursion the list is traversed
 * 			incremented by 1 on each successful function
 * 			call. Allows the satellites to be counted.
 * @return int 
 */
int SatelliteLauncher::count() {
	if (this->_successor == NULL) {
		return 1;
	}
	return 1 + this->_successor->count();
}