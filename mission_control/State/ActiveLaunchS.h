#include <exception>
using namespace std;

#ifndef __ActiveLaunchS_h__
#define __ActiveLaunchS_h__

#include "State.h"

class Rocket;

class ActiveLaunchS: public State
{
	public: 
		void changeState(Rocket* aR);
		
		/**
		 * @brief Prints out a message explaining the
		 * @param aR The rocket being handled 
		 */
		void handle(Rocket* aR) override;

		public: State *clone() override;
};

#endif