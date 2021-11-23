#include <iostream>

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

using namespace std;

void observer_test();
// void storage_test();
void builder_test();

int main()
{
    observer_test();
    // storage_test();
    // builder_test();
    return 0;
}

void observer_test() {
  cout << "================OBSERVER TEST================" << endl;
  Booster *fHeavy = new FalconHeavy();
  Booster *f = new Falcon();
  Booster *sStage = new SecondStage();

  FuelObserver *fObs1 = new FuelObserver("Observer-1"),
               *fObs2 = new FuelObserver("Observer-2"),
               *fObs3 = new FuelObserver("Observer-3"),
               *fObs4 = new FuelObserver("Observer-4"),
               *fObs5 = new FuelObserver("Observer-5");

  fHeavy->setLOXfuelLevel(100);
  fHeavy->setRP1fuelLevel(100);


    fHeavy->setLOXfuelLevel(100);
    fHeavy->setRP1fuelLevel(100);
    fHeavy->setBoosterId(1);

    f->setLOXfuelLevel(100);
    f->setRP1fuelLevel(100);
    f->setBoosterId(3);

    sStage->setLOXfuelLevel(100);
    sStage->setRP1fuelLevel(100);
    sStage->setBoosterId(2);


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

// void storage_test() {
//   cout << "================STORAGE TEST================" << endl;

//   // create aggregate
//   RocketAggregate *rocket_aggregate = new RocketAggregate;

//   // create a memento to remove later
//   RocketMemento *remove_memento = new RocketMemento("stationary");

//   // populate aggregate vector
//   rocket_aggregate->add(new RocketMemento("launched"));
//   rocket_aggregate->add(new RocketMemento("building"));
//   rocket_aggregate->add(new RocketMemento("launching"));
//   rocket_aggregate->add(remove_memento);
//   rocket_aggregate->add(new RocketMemento("low fuel"));
//   rocket_aggregate->add(new RocketMemento("building"));

//   // create iterator
//   Iterator *rocket_iterator = rocket_aggregate->createIterator();

//   // print aggregate vector using iterator
//   for (; !rocket_iterator->end(); rocket_iterator->next()) {
//     cout << rocket_iterator->getCurr()->getRocketState() << endl;
//   }

//   // remove remove_memento from aggregate vector
//   rocket_aggregate->remove(remove_memento);

//   // reset iterator to first element
//   rocket_iterator->start();

//   cout << "==============" << endl;

//   // print aggregate vector using iterator
//   for (; !rocket_iterator->end(); rocket_iterator->next()) {
//     cout << rocket_iterator->getCurr()->getRocketState() << endl;
//   }

//   cout << "==============STORAGE TEST DONE==============" << endl;
// }

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
