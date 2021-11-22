#include <exception>
using namespace std;

#include "FuelS.h"
#include "LaunchS.h"

/**
 * @brief Change the rocket state from Fueling state.
 * 
 * @param aR 
 */
void FuelS::changeState(Rocket* aR) {
	aR->setState(new LaunchS());
	delete this;
}