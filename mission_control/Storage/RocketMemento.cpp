#include "RocketMemento.h"

/* testing */
RocketMemento::RocketMemento(Propulsion* _prop, Payload* _payload, State* _state, Rocket::RocketType _RocketType) {
  _propulsion_store = _prop->clone();
  _payload_store = _payload->clone();
  _state_store = _state;
  _RocketType_store = _RocketType;
}
  
Propulsion* RocketMemento::getPropulsion() {
  return _propulsion_store;
}

Payload* RocketMemento::getPayload() {
  return _payload_store;
}

State* RocketMemento::getState() {
  return _state_store;
}

Rocket::RocketType RocketMemento::getType() {
  return _RocketType_store;
}

RocketMemento::~RocketMemento() {
  delete _propulsion_store;
  delete _payload_store;
  delete _state_store;
}