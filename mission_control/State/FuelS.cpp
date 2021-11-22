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