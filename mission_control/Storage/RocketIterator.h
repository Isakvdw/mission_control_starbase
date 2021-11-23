#include <exception>
#include <vector>
using namespace std;

#ifndef __RocketIterator_h__
#define __RocketIterator_h__

#include "Iterator.h"
#include "RocketAggregate.h"
#include "RocketMemento.h"

class RocketIterator : public Iterator
{
private:
	/// A vector containing pointers to RocketMemento objects
	vector<RocketMemento *> *_curr;

	/// An integer to keep track of the current position of the iterator
	int current;

protected:
	friend class RocketAggregate;

	/**
	 * @brief A parameterized constructor
	 * @param c a pointer to a vector containing pointers to RocketMemento objects
	 */
	RocketIterator(vector<RocketMemento *> *c);

public:
	// RocketAggregate *rocketAggregate;
	// Builder *rocketBuilder;

	/**
	 * @brief Move on to next element
	 * @return element that is being pointed to after move
	 */
	RocketMemento *next();

	/**
	 * @brief Check if currently at last element
	 * @return return true if at last element, else return false
	 */
	bool end();

	/**
	 * @brief Move to the first element
	 * @return The first element
	 */
	RocketMemento *start();

	/**
	 * @brief Returns the current element
	 * @return element that is currently being pointed to
	 */
	RocketMemento *getCurr();
};

#endif
