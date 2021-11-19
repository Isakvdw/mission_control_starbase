
#include "Rocket.h"
#include "Propulsion.h"
#include "Payload.h"
#include "MissionControlStarbase.h"
#include "State.h"

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

