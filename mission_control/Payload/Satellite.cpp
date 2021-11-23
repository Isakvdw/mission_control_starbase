#include <exception>
#include <iostream>
using namespace std;

#include "Satellite.h"

/**
 * @brief Construct a new Satellite::Satellite object 
 * @details Creates normal Satellite.
 */
Satellite::Satellite() {
	
}

/**
 * @brief Construct a new Satellite::Satellite object
 * @details Copy constructor to make copied Satellites
 * 			from existing Satellites.
 * @param obj 
 */
Satellite::Satellite(const Satellite& obj) {
	
}

/**
 * @brief Clones satellite and returns new one.
 * @details Creates a cloned Satellite when a Satellite 
 * 			calls to clone itself.
 * @return Satellite* 
 */
Satellite* Satellite::clone() {
	return new Satellite(*this);
}

void Satellite::satBoot(int v) {
	cout << "Satellite: " << v << " Online" << endl;
}


void Satellite::handleRequest(int number) {
	satBoot(number);
	if (this->_successor == NULL)
	{
		return;
	}
	else
	{
		this->_successor->handleRequest(++number);
		delete this->_successor;
		this->_successor = NULL;
		return;
	}
}
