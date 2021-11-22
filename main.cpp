#include <iostream>
#include "FuelObserver.h"
#include "Engine.h"
#include "SecondStage.h"
#include "Falcon.h"
#include "FalconHeavy.h"

using namespace std;

int main() {
    cout << "================OBSERVER TEST================" << endl;
    Booster *fHeavy = new FalconHeavy();
    Booster *f = new Falcon();
    Booster *sStage = new SecondStage();
    Engine *eng = new Engine("Vacuum");


    cout << "==============OBSERVER TEST DONE==============" << endl;
    return 0;
}