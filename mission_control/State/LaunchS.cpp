#include <exception>
using namespace std;

#include "LaunchS.h"
#include "ActiveLaunchS.h"

/**
 * @brief Change rocket state from Launch prep state.
 * @details Changes the rocket state from being ready for launch to Active Launch state.
 * 			This just simply calls the rocket set state and passes the new Active Launch state.
 * @param aR 
 */
void LaunchS::changeState(Rocket* aR) {
	aR->setState(new ActiveLaunchS());
}

void LaunchS::handle(Rocket *aR) {
	cout << "Launch commenced" << endl;
	for (int k = 0; k < 3; k++) {
		int bound =  (aR->getRocketType() == Rocket::FALCON9) ? 1 : 3;
		for (int i = 0; i < bound; i++) {
			aR->getFirstStage(i)->setLOXfuelLevel(aR->getFirstStage(i)->getLOXfuelLevel() - 20);
			aR->getFirstStage(i)->setRP1fuelLevel(aR->getFirstStage(i)->getRP1fuelLevel() - 20);
			aR->getFirstStage(i)->notify();
		}
	}
	
	for (int k = 0; k < 4; k++) {
		aR->getSecondStage()->setLOXfuelLevel(aR->getSecondStage()->getLOXfuelLevel() - 30);
		aR->getSecondStage()->setRP1fuelLevel(aR->getSecondStage()->getRP1fuelLevel() - 30);
		aR->getSecondStage()->notify();
	}
	cout << "Launch concluded" << endl;
}

State* LaunchS::clone() {
	return new LaunchS();
}