#include <exception>
#include <iostream>
#include <string>
#include <iostream>
using namespace std;

#include "Starlink.h"
#include "SatelliteLauncher.h"
#include "Payload.h" 

Starlink::Starlink() {
	this->_satellites = NULL;
}

string Starlink::getPayloadDescription() {
	string out = "Number of Satellites: "+to_string(_satellites->count());
	return out;
}

void Starlink::printPayload() {
	cout<<getPayloadDescription()<<endl;
}

