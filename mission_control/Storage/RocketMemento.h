
#ifndef __RocketMemento_h__
#define __RocketMemento_h__
#include <iostream>
#include <string>

using namespace std;

// #include "Caretaker.h"
//#include "Aggregate.h"

// class Caretaker;
// class Aggregate;

class RocketMemento
{
private:
  friend class Rocket;

  /// state of the rocket to be stored by the memento
  string _rocket_state;

  /**
	 * @brief A parameterized constructor
	 * @param s a string containing the rocket state
	 */
  RocketMemento(string s);

public:
  /**
	 * @brief Getter for the rocket state
	 * @return the rocket state as a string
	 */
  string getRocketState();
  // Caretaker *caretaker;
  // Aggregate *rocketAggregate;
};

#endif
