#include <exception>
using namespace std;

#include "Falcon.h"

void Falcon::operation()
{
	throw "Not yet implemented";
}

string Falcon::getName()
{
	return "Falcon-" + to_string(this->getBoosterId());
}

Propulsion* Falcon::clone() {
	Falcon* clone =  new Falcon(); // hmmm
	clone->_lOXfuelLevel = this->_lOXfuelLevel;
	clone->_rP1fuelLevel = this->_lOXfuelLevel;
	clone->setBoosterId(this->getBoosterId());

	for (auto it = this->_children.begin(); it < this->_children.end(); it++) {
		if(*it) clone->add((*it)->clone());
	}
	return clone; 
}