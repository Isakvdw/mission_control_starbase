#include <iostream>
#include "Propulsion/FuelObserver.h"
#include "Propulsion/Engine.h"
#include "Propulsion/SecondStage.h"
#include "Propulsion/Falcon.h"
#include "Propulsion/FalconHeavy.h"

using namespace std;

void observer_test();

int main() {
    observer_test();
    return 0;
}

void observer_test() {
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

    sStage->detach(fObs5);
    sStage->detach(nullptr);
    sStage->detach(fObs1);


    fHeavy->notify();
    f->notify();
    sStage->notify();

    for (int i = 1; i <= 12; i++) {
        fHeavy->setLOXfuelLevel(fHeavy->getLOXfuelLevel() - 5);
        fHeavy->setRP1fuelLevel(fHeavy->getRP1fuelLevel() - 11);
        fHeavy->notify();

        f->setLOXfuelLevel(f->getLOXfuelLevel() - 10);
        f->setRP1fuelLevel(f->getRP1fuelLevel() - 5);
        f->notify();

        sStage->setLOXfuelLevel(sStage->getLOXfuelLevel() - 13);
        sStage->setRP1fuelLevel(sStage->getRP1fuelLevel() - 10);
        f->notify();
    }

    delete fObs5;
    delete fObs4;
    delete fObs3;
    delete fObs2;
    delete fObs1;

    delete sStage;
    delete f;
    delete fHeavy;

    cout << "==============OBSERVER TEST DONE==============" << endl;
}


