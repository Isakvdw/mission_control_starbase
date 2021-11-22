#include <exception>
using namespace std;

#include "BuildS.h"
#include "FuelS.h"

/**
 * @brief Changes the state of the rocket from Build state.
 * @details Changes the rocket state from being built to Fueling state.
 * 			This just simply calls the rocket set state and passes the new Fuel state.
 * @param aR 
 */
void BuildS::changeState(Rocket* aR) {
	aR->setState(new FuelS());
}