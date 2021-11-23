
#include "Rocket.h"

Propulsion* Rocket::getPropulsion() {
	return this->_propulsion;
}

Booster* Rocket::getSecondStage() {
	return (Booster*)_propulsion;
}

Booster* Rocket::getFirstStage(int index) {
	return getSecondStage()->getChildBooster(index);
}

void Rocket::setPropulsion(Propulsion* aPropulsion) {
	this->_propulsion = aPropulsion;
}

Payload* Rocket::getPayload() {
	return this->_payload;
}

void Rocket::setPayload(Payload* aPayload) {
	this->_payload = aPayload;
}

State* Rocket::getState() {
	return this->_state;
}

void Rocket::setState(State* aState) {
	this->_state = aState;
}

Rocket::Rocket(){
	_propulsion=NULL;
	_payload=NULL;
	_state=NULL;
}

Rocket::~Rocket() {
	delete _propulsion;
	delete _payload;
	// delete _state;
}
RocketMemento* Rocket::Save() {
	return new RocketMemento(_propulsion, _payload, _state, _rocketType);
}

void Rocket::Restore(RocketMemento* aRockMem) {
	_propulsion = aRockMem->getPropulsion();
	_payload = aRockMem->getPayload();
	_state = aRockMem->getState();
}
