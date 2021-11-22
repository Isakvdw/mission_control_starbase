#include <iostream>
#include "Satellite.h"
#include "SatelliteFactory.h"
#include "Starlink.h"
using namespace std;
int main() {
    Starlink * SL = new Starlink();
    SatelliteFactory * SF = new SatelliteFactory();
    for (int x = 0; x < 5; x++)
    {
        SL->addSat(SF->createComponent());
    }
    SL->LaunchAllSatellites();
    SL->printPayload();
    SL->LaunchAllSatellites();
    return 0;
}