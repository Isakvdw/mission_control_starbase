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

void ActiveLaunchS::handle(Rocket *aR) {
    cout << "Real Launch Commences" << endl;
    aR->setState(new FuelS());
    aR->getState()->handle(aR);
    cout << "\tPayload is: ";
    aR->getPayload()->printPayload();
    aR->getPayload()->launchPayload();
    cout << endl;
    aR->setState(new LaunchS());
    aR->getState()->handle(aR);
    cout << "Real Launch Concludes" << endl;
}

State* ActiveLaunchS::clone() {
    return new ActiveLaunchS();
}
