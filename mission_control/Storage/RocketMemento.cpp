#include "RocketMemento.h"

/* testing */
RocketMemento::RocketMemento(Propulsion* _prop, Payload* _payload, State* _state) {
  _propulsion_store = _prop;
  _payload_store = _payload;
  _state_store = _state;
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

RocketMemento::~RocketMemento() {
  delete _propulsion_store;
  delete _payload_store;
  // delete _state_store;
}