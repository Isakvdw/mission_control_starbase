#include <iostream>
#include "DragonCrew.h"
#include "Satellite.h"
using namespace std;
int main() {
    Payload * test = new DragonCrew();
    
    cout<<test->getPayloadDescription()<<endl;
    return 0;
}