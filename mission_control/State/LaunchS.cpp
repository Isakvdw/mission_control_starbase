#include <exception>
using namespace std;

#include "LaunchS.h"
#include "ActiveLaunchS.h"

/**
 * @brief Change rocket state from Launch prep state.
 * 
 * @param aR 
 */
void LaunchS::changeState(Rocket* aR) {
	aR->setState(new ActiveLaunchS());
	delete this;
}