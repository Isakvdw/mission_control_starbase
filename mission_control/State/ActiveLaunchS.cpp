#include <exception>
using namespace std;

#include "ActiveLaunchS.h"
#include "LaunchS.h"
#include "FuelS.h"

/**
 * @brief Change rocket state from Active Launch state.
 * @details You can not change state further while in Active Launch state.
 * @param aR 
 */
void ActiveLaunchS::changeState(Rocket* aR) {
	aR->setState(new FuelS());
    /// refuel
    aR->setState(new LaunchS());
}
