#include <exception>
using namespace std;

#ifndef __FuelS_h__
#define __FuelS_h__

#include "State.h"

class FuelS: public State
{
	public:
		void changeState(Rocket* aR);

		/**
		 * @brief Refuels the rocket
		 * @param aR The rocket being handled
		 * @details This state refuels the rocket to 100%, it will also notify the observers of the rocket 
		 */
		void handle(Rocket* aR) override;

		public: State *clone() override;
};

#endif