#include <iostream>
#include "MissionControlStarbase.h"
#include "Builder/ConcreteBuilder.h"
#include "Propulsion/Engine.h"
#include "Propulsion/Falcon.h"
#include "Propulsion/FalconHeavy.h"
#include "Propulsion/FuelObserver.h"
#include "Propulsion/SecondStage.h"
#include "Storage/Aggregate.h"
#include "Storage/Iterator.h"
#include "Storage/RocketAggregate.h"
#include "Storage/RocketIterator.h"
#include "Storage/RocketMemento.h"
#include "Storage/Caretaker.h"

using namespace std;

void observer_test();
// void storage_test();
void builder_test();
void booster_clone_test();

void simulation();

int main()
{
    simulation();
    // observer_test();
    // storage_test();
    // builder_test();
    // booster_clone_test();
    return 0;
}

void simulation() {
    ConcreteBuilder builder(Rocket::FALCONHEAVY, Payload::STARLINK);
    builder.setFirstStageBoosters();
    builder.setPayload(50);
    Rocket* r = builder.buildRocket();
    
    FuelObserver* observer = new FuelObserver();
    FuelObserver* firstStageO = new FuelObserver();
    
    r->getSecondStage()->attach(observer);
    observer->setSubjectBooster(r->getSecondStage());
    
    r->getFirstStage(1)->attach(firstStageO);
    firstStageO->setSubjectBooster(r->getFirstStage(1));

    r->getState()->changeState(r);
    r->getState()->handle(r);
    r->getState()->changeState(r);
    r->getState()->handle(r);

    Caretaker* caretaker = new Caretaker();
    RocketAggregate* aggr = new RocketAggregate();
    aggr->add(r->Save());
    aggr->add(r->Save());
    aggr->add(r->Save());
    caretaker->batchStore(aggr);
    caretaker->batchRun();

    r->getState()->changeState(r); // Go to real launch
    r->getState()->handle(r);
}

void booster_clone_test() {
        // Rocket::FALCON9 ------ Payload::STARLINK
    ConcreteBuilder * CB = new ConcreteBuilder(Rocket::FALCONHEAVY, Payload::STARLINK);
    CB->setFirstStageBoosters();
    CB->setPayload(10);
    Rocket * R = CB->buildRocket();
    ((Booster*) R->getPropulsion())->getChildBooster(1)->setLOXfuelLevel(100);
    Booster* prop = (Booster*) R->getPropulsion()->clone();
    cout << prop->getBoosterId() << endl;
    cout << prop->getChildBooster(0)->getBoosterId() << endl; 
    cout << prop->getChildBooster(1)->getBoosterId() << endl; 
    cout << prop->getChildBooster(1)->getLOXfuelLevel() << endl; 
    cout << prop->getChildBooster(2)->getBoosterId() << endl; 
 
    R->getPayload()->printPayload();
    delete CB;
    delete R;
}

void observer_test()
{
    cout << "================OBSERVER TEST================" << endl;
    Booster *fHeavy = new FalconHeavy();
    Booster *f = new Falcon();
    Booster *sStage = new SecondStage();

    FuelObserver* fObs1 = new FuelObserver();
    FuelObserver* fObs2 = new FuelObserver();
    FuelObserver* fObs3 = new FuelObserver();
    FuelObserver* fObs4 = new FuelObserver();
    FuelObserver* fObs5 = new FuelObserver();

    fHeavy->setLOXfuelLevel(100);
    fHeavy->setRP1fuelLevel(100);
    fHeavy->setBoosterId(1);

    f->setLOXfuelLevel(100);
    f->setRP1fuelLevel(100);
    f->setBoosterId(3);

    sStage->setLOXfuelLevel(100);
    sStage->setRP1fuelLevel(100);
    sStage->setBoosterId(2);

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

void builder_test() {
    // Rocket::FALCON9 ------ Payload::STARLINK
    ConcreteBuilder * CB = new ConcreteBuilder(Rocket::FALCON9, Payload::STARLINK);
    CB->setFirstStageBoosters();
    CB->setPayload(10);
    Rocket * R = CB->buildRocket();
    R->getPayload()->printPayload();
    delete CB;
    delete R;
}

/*
getSec()      SecondStage
                  |
                  |
                  |   0      1      2
getFirst(int) Engine, First, First, First
                       |
                       |
                    eng 1..9
*/

/*
            SecondStage <- s1
                  |
                  |
                  |   0      1      2
         Engine, First, First, First
                       |
                       |
                    eng 1..9
*/
