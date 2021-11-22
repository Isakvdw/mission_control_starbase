
#ifndef __RocketMemento_h__
#define __RocketMemento_h__
#include <iostream>
#include <string>

using namespace std;

// #include "Caretaker.h"
//#include "Aggregate.h"

// class Caretaker;
// class Aggregate;

class RocketMemento {
 private:
  friend class Rocket;
  string _rocket_state;
  RocketMemento(string s);

 public:
  string getRocketState();
  // Caretaker *caretaker;
  // Aggregate *rocketAggregate;
};

#endif
