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