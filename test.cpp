#include <iostream>
#include "DragonCrew.h"
#include "Satellite.h"
using namespace std;
int main() {
    DragonCrew * test = new DragonCrew();
    test->insertCrew("Adir Miller","Colonel");
    test->insertCrew("Jack Boxer","Commander");
    test->insertCrew("Sam Buchen","Pilot");
    test->insertCrew("Adir Miller","Colonel");
    test->insertCrew("Jack Boxer","Commander");
    test->insertCrew("Sam Buchen","Pilot");
    test->insertCrew("Adir Miller","Colonel");
    test->insertCrew("Jack Boxer","Commander");
    test->insertCrew("Sam Buchen","Pilot");
    cout<<test->getPayloadDescription()<<endl;
    return 0;
}