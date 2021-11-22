#include <exception>
using namespace std;

#include "ConcreteBuilder.h"

ConcreteBuilder::ConcreteBuilder() {
	_constructionRocket = new Rocket();
	_numFirstStage = 0;
	_secondStageSet = false;
	_currSecondStage = nullptr;
}

void ConcreteBuilder::setSecondStage(Booster* aSecondStage) {
	if (_currSecondStage == aSecondStage) return; // Do nothing if same second stage booster is added twice
	if (aSecondStage == nullptr) { // if a nullptr is passed and currentSecondStage is not null
		_secondStageSet == false; // indicate that there is no longer a second stage
		// add all the children of the existing second stage to the buffer
		Propulsion *propPtr;
		while (propPtr = _currSecondStage->popBack()) {
			_propulsionBuffer.push_front(propPtr); // Move all Propulsion elements from currSecondStage into the buffer
		}
	} else {
		_secondStageSet = true;
		for (Propulsion *prop : _propulsionBuffer) {
			aSecondStage->add(prop);	// add all elements from buffer into 
		}
		_propulsionBuffer.clear(); // clear buffer
	}
}

Rocket* ConcreteBuilder::buildRocket() {
	Rocket *rocket = _constructionRocket;
	_constructionRocket = nullptr;
	return rocket;
}

