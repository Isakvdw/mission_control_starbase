#include <exception>
using namespace std;

#ifndef __State_h__
#define __State_h__

#include "../Rocket.h"

class State
{
	/**
	 * @brief This function handles state specific functionality
	 * @param aR The rocket that should be used for handling
	 * @details see children classes for details
	 */
	public: virtual void handle(Rocket *aR) = 0;

	/**
	 * @brief changes the state of the rocket
	 * @param aR The rocket which is changing state
	 * @details See childrem classes for details
	 */
	public: virtual void changeState(Rocket* aR) = 0;

	/**
	 * @brief returns a clone of the current state
	 */
	public: virtual State *clone()=0;
};

#endif
