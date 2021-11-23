
#ifndef __RocketMemento_h__
#define __RocketMemento_h__
#include <iostream>
#include <string>

using namespace std;

// #include "Caretaker.h"
//#include "Aggregate.h"

// class Caretaker;
// class Aggregate;
#include "../Rocket.h"

class State;

class RocketMemento {
private:
  
  friend class Rocket;

  Propulsion* _propulsion_store;
  Payload* _payload_store;
  State* _state_store;
  Rocket::RocketType _RocketType_store;

  /**
	 * @brief Constructor for RocketMemento
	 * @param[in] _prop The propulsion of the rocket
	 * @param[in] _payload The payload of the rocket
	 * @param[in] _state The state of the rocket
	 */
  RocketMemento(Propulsion* _prop, Payload* _payload, State* _state, Rocket::RocketType _RocketType);

 public:
  ~RocketMemento();
  Propulsion* getPropulsion();
  Payload* getPayload();
  State* getState();
  Rocket::RocketType getType();
  // Caretaker *caretaker;
  // Aggregate *rocketAggregate;
};

#endif
