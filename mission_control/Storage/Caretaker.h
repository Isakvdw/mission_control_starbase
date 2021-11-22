#include <exception>
using namespace std;

#ifndef __Caretaker_h__
#define __Caretaker_h__

#include "RocketAggregate.h"
#include "RocketIterator.h"
// #include "RocketMemento.h"

class RocketMemento;

class Caretaker {
 private:
  Aggregate *_mementos;

 public:
  Iterator *rocketIterator;
  RocketMemento *rocketMemento;
  Aggregate *rocketAggregate;
  Iterator *createIterator();
};

#endif
