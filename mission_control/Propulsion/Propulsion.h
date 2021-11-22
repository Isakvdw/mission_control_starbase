#include <exception>
#include <vector>
using namespace std;

#ifndef __Propulsion_h__
#define __Propulsion_h__

#include "Observer.h"

class Observer;

class Propulsion
{
	/// A list of @p Observer objects attached
	private: vector<Observer*> _observerList;

	/**
	 * @param[in] aP - The propulsion object to be added
	 * @details see child classes for implementation details
	 */
	public: virtual void add(Propulsion* aP) = 0;

	/**
	 * @param[in] aP - The propulsion object to be removed
	 * @details see child classes for implementation details
	 */
	public: virtual void remove(Propulsion* aP) = 0;

	
	public: virtual void operation() = 0;

	/**
	 * Adds an observer to the observer list
	 * @param[in] aO A pointer to the observer to be added to the observer list 
	 * @note 
	 * 		- Observer also has to register with respective object to function correctly
	 */
	public: void attach(Observer* aO);

	/**
	 * @brief Removes an observer from the observer list
	 * @param aO The observer to be removed from the observer list 
	 */
	public: void detach(Observer* aO);

	/**
	 * Notifies all observers in the observer list
	 */
	public: void notify();
};

#endif
