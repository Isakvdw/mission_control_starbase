#include <exception>
using namespace std;

#ifndef __Iterator_h__
#define __Iterator_h__

#include "RocketMemento.h"

class Iterator
{
public:
	/**
	 * @brief Move on to next element
	 * @return element that is being pointed to after move
	 */
	virtual RocketMemento *next() = 0;

	/**
	 * @brief Check if currently at last element
	 * @return return true if at last element, else return false
	 */
	virtual bool end() = 0;

	/**
	 * @brief Move to the first element
	 * @return The first element
	 */
	virtual RocketMemento *start() = 0;

	/**
	 * @brief Returns the current element
	 * @return element that is currently being pointed to
	 */
	virtual RocketMemento *getCurr() = 0;
};

#endif
