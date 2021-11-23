#include <exception>
using namespace std;

#ifndef __Caretaker_h__
#define __Caretaker_h__

// #include "RocketAggregate.h"
#include "RocketIterator.h"
// #include "RocketMemento.h"

class RocketMemento;

class Caretaker {
 private:
  RocketAggregate *_mementos;
  Iterator *_intIter;
 public:  
  Caretaker();
  ~Caretaker();
  Iterator* createIterator();
  void storeRocket(RocketMemento* rockMem);
  void batchStore(RocketAggregate* aBatch);
  RocketMemento* RestoreLast();
  void removeLast();
};

#endif
