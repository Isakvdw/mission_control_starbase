#include <exception>
using namespace std;

#ifndef __LaunchS_h__
#define __LaunchS_h__

#include "State.h"

class LaunchS: public State
{
	public: 
		void changeState(Rocket* aR);

		/**
		 * @brief Launches the rocket
		 * @param aR The rocket being handled 
		 * @details Launches the rocket by modifying the fuel values, also notifies all observers
		 */
		void handle(Rocket* aR) override;

		public: State *clone() override;
};

#endif