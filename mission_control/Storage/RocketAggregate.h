#include <exception>
#include <vector>
using namespace std;

#ifndef __RocketAggregate_h__
#define __RocketAggregate_h__

#include "RocketIterator.h"
#include "Aggregate.h"

class RocketAggregate : public Aggregate
{
private:
	/// vector of pointers to RocketMemento objects
	vector<RocketMemento *> _mementos;

public:
	/**
	 * @brief Add a RocketMemento to the vector
	 * @param[in] aR pointer to a RocketMemento object
	 */
	void add(RocketMemento *aR);

	/**
	 * @brief Remove a RocketMemento from the vector
	 * @param[in] aR pointer to a RocketMemento object
	 */
	void remove(RocketMemento *aR);

	/**
	 * @brief Create an iterator
	 * @return newly created iterator
	 */
	Iterator *createIterator();
};

#endif
