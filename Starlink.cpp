#include <exception>
#include <string>
#include <iostream>
using namespace std;

#include "Starlink.h"
#include "SatelliteLauncher.h"
#include "Payload.h"

string Starlink::getPayloadDescription() {
	string out = "Number of Satellites: "+to_string(_satellites->count());
	return out;
}

void Starlink::printPayload() {
	cout<<getPayloadDescription()<<endl;
}

