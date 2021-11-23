#include <exception>
using namespace std;

#ifndef __Aggregate_h__
#define __Aggregate_h__

class Iterator;

// #include "RocketMemento.h"
class RocketMemento;

class Aggregate
{
public:
	// Caretaker *caretaker;
	// RocketMemento *rocketMemento;

	/**
	 * @brief Add a RocketMemento to the vector
	 * @param[in] aR pointer to a RocketMemento object
	 */
	virtual void add(RocketMemento *aR) = 0;

	/**
	 * @brief Remove a RocketMemento from the vector
	 * @param[in] aR pointer to a RocketMemento object
	 */
	virtual void remove(RocketMemento *aR) = 0;

	/**
	 * @brief Create an iterator
	 * @return newly created iterator
	 */
	virtual Iterator *createIterator() = 0;
};

#endif
