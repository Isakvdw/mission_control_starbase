#include <exception>
using namespace std;

#ifndef __BuildS_h__
#define __BuildS_h__

#include "State.h"

class BuildS: public State
{
	public: 
		/**
		 * @brief Changes to the Fuel State
		 * @param aR The rocket changing state
		 */
		void changeState(Rocket* aR) override;

		/**
		 * @brief Prints out a message explaining the
		 * @param aR The rocket being handled 
		 */
		void handle(Rocket* aR) override;

		public: State *clone() override;
};

#endif