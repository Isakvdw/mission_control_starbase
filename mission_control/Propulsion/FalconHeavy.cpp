#include <exception>
using namespace std;

#include "FalconHeavy.h"

Propulsion* FalconHeavy::clone() {
	FalconHeavy* clone =  new FalconHeavy(); // hmmm
	clone->_lOXfuelLevel = this->_lOXfuelLevel;
	clone->_rP1fuelLevel = this->_lOXfuelLevel;
	clone->setBoosterId(this->getBoosterId());

	for (auto it = this->_children.begin(); it < this->_children.end(); it++) {
		if(*it) clone->add((*it)->clone());
	}
	return clone; 
}

string FalconHeavy::getName()
{
	return "Falcon Heavy-" + to_string(this->getBoosterId());
}