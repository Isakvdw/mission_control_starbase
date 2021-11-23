#include <exception>
using namespace std;

#include "SecondStage.h"

void SecondStage::operation()
{
	throw "Not yet implemented";
}

Propulsion* SecondStage::clone() {
	SecondStage* clone =  new SecondStage(); // hmmm
	clone->_lOXfuelLevel = this->_lOXfuelLevel;
	clone->_rP1fuelLevel = this->_lOXfuelLevel;
	clone->setBoosterId(this->getBoosterId());

	for (auto it = this->_children.begin(); it < this->_children.end(); it++) {
		if(*it) clone->add((*it)->clone());
	}
	return clone; 
}

string SecondStage::getName()
{
	return "Second Stage-" + to_string(this->getBoosterId());
}

Booster* SecondStage::getChildBooster(int index) {
	if (index + 1 < _children.size()) {
		return (Booster*)_children[index + 1];
	}
	return nullptr;
}