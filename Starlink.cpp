#include <exception>
#include <iostream>
#include <string>
#include <iostream>
using namespace std;

#include "Starlink.h"
#include "SatelliteLauncher.h"
#include "Payload.h" 

Starlink::Starlink() {
	this->_payloadDescription = "Cargo of satellites to be released into orbit!";
	this->_satellites = NULL;
}

void Starlink::LaunchAllSatellites() {
	this->printPayload();
	if (this->_satellites != NULL) {
		this->_satellites->handleRequest();
		delete this->_satellites;
		this->_satellites = NULL;
		cout<<"All satellites have launched!"<<endl;
		return;
	}
	else
	{
		cout<<"No satellites available to launch!"<<endl;
	}
}

void Starlink::addSat(SatelliteLauncher* Sat) {
	if (this->_satellites == NULL)
	{
		this->_satellites = Sat;
	}
	else
	{
		this->_satellites->add(Sat);
	}
}

string Starlink::getPayloadDescription() {
	string out = "";
	if (_satellites == NULL) {
		out = "Number of Satellites: 0";
		out = out + "\n" + this->_payloadDescription;
	}
	else
	{
		out = "Number of Satellites: "+to_string(_satellites->count());
		out = out + "\n" + this->_payloadDescription;
	}
	return out;
}

void Starlink::printPayload() {
	cout<<getPayloadDescription()<<endl;
}

