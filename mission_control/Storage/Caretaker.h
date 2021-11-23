#include <exception>
using namespace std;

#ifndef __Caretaker_h__
#define __Caretaker_h__

// #include "RocketAggregate.h"
#include "RocketIterator.h"
// #include "RocketMemento.h"
#include "../MissionControlStarbase.h"

class RocketMemento;

class Caretaker {
 private:
  RocketAggregate *_mementos;
  Iterator *_intIter;
  MissionControlStarbase *MCS;
 public:  
  Caretaker();
  ~Caretaker();
  /**
	 * @brief Creates an iterator that is used to traverse the memento list
	 * @return return the iterator
	 */
  Iterator* createIterator();

  /**
	 * @brief Adds a rocket to the memento list
	 * @param rockMem a pointer to a RocketMemento to be added to memento list
	 */
  void storeRocket(RocketMemento* rockMem);

  /**
	 * @brief Adds in a batch of rockets
	 * @param aBatch a Batch t of rockets that will server as the new memento list
	 */
  void batchStore(RocketAggregate* aBatch);

  void batchRun();

  /**
	 * @brief Returns lastly stored rocket's state
	 * @return returns lastly added RocketMemento
	 */
  RocketMemento* RestoreLast();
  
  void removeLast();
};

#endif
