#include <exception>
using namespace std;

#include "BuildS.h"
#include "FuelS.h"

/**
 * @brief Changes the state of the rocket from Build state.
 * 
 * @param aR 
 */
void BuildS::changeState(Rocket* aR) {
	aR->setState(new FuelS());
	delete this;
}