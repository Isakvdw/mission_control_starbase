#include <exception>
using namespace std;

#include "FuelS.h"
#include "LaunchS.h"

/**
 * @brief Change the rocket state from Fueling state.
 * @details Changes the rocket state from being fueled to launching state.
 * 			This just simply calls the rocket set state and passes the new Launch state.
 * @param aR 
 */
void FuelS::changeState(Rocket* aR) {
	aR->setState(new LaunchS());
}

void FuelS::handle(Rocket* aR) {
	cout << "Refueling commenced" << endl;
	aR->getSecondStage()->setLOXfuelLevel(100);
	aR->getSecondStage()->setRP1fuelLevel(100);
	aR->getSecondStage()->notify();

	int bound =  (aR->getRocketType() == Rocket::FALCON9) ? 1 : 3;
	for (int i = 0; i < bound; i++) {
		aR->getFirstStage(i)->setLOXfuelLevel(100);
		aR->getFirstStage(i)->setRP1fuelLevel(100);
		aR->getFirstStage(i)->notify();
	}
	cout << "Refueling concluded" << endl;
}

State* FuelS::clone() {
	return new FuelS();
}