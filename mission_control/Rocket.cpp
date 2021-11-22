
#include "Rocket.h"

Propulsion* Rocket::getPropulsion() {
	return this->_propulsion;
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

