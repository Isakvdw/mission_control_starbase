#include <iostream>
#include "Dragon.h"
#include "DragonCrew.h"
#include "Satellite.h"
using namespace std;
int main() {
    Payload * test = new Dragon();
    cout<<test->getPayloadDescription()<<endl;
    return 0;
}