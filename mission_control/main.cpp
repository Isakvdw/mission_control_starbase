#include <iostream>
#include "Propulsion/PropulsionG.h"
#include "Payload/PayloadG.h"
#include "State/StateG.h"
#include "Storage/StorageG.h"
#include "Builder/BuilderG.h"

using namespace std;

int main() {
    cout << "================OBSERVER TEST================" << endl;
    Booster *fHeavy = new FalconHeavy();
    Booster *f = new Falcon();
    Booster *sStage = new SecondStage();

    FuelObserver *fObs1 = new FuelObserver("Observer-1")
                , *fObs2 = new FuelObserver("Observer-2")
                , *fObs3 = new FuelObserver("Observer-3")
                , *fObs4 = new FuelObserver("Observer-4")
                , *fObs5 = new FuelObserver("Observer-5");

    fHeavy->setLOXfuelLevel(100);
    fHeavy->setRP1fuelLevel(100);

    f->setLOXfuelLevel(100);
    f->setRP1fuelLevel(100);

    sStage->setLOXfuelLevel(100);
    sStage->setRP1fuelLevel(100);

    fHeavy->attach(fObs1);
    fObs1->setSubjectBooster(fHeavy);
    fHeavy->attach(fObs2);
    fObs2->setSubjectBooster(fHeavy);

    f->attach(fObs3);
    fObs3->setSubjectBooster(f);

    sStage->attach(fObs4);
    sStage->attach(fObs5);
    fObs4->setSubjectBooster(sStage);
    fObs5->setSubjectBooster(sStage);

    fHeavy->notify();
    f->notify();
    sStage->notify();

    delete fObs5;
    delete fObs4;
    delete fObs3;
    delete fObs2;
    delete fObs1;

    delete sStage;
    delete f;
    delete fHeavy;

    cout << "==============OBSERVER TEST DONE==============" << endl;
    return 0;
}
