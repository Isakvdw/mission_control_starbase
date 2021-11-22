#include <exception>
#include <iostream>
#include <string>
#include <iostream>
using namespace std;

#include "Starlink.h"

/**
 * @brief Construct a new Starlink:: Starlink object
 * 
 */
Starlink::Starlink() {
	this->_payloadDescription = "Cargo of satellites to be released into orbit!";
	this->_satellites = NULL;
}

/**
 * @brief Destroy the Starlink:: Starlink object
 * Delete the array of satelliteLaunchers.
 */
Starlink::~Starlink() { 
	if (this->_satellites != NULL) {
		this->_satellites->handleRequest();
		delete this->_satellites;
		this->_satellites = NULL;
		return;
	}
}

/**
 * @brief Simulates the the ejection by calling the head Satellite
 * to Handle the request which goes down the chain deleting and
 * detaching satellites.
 * 
 */
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

/**
 * @brief Add satellite to the chain.
 * 
 * @param Sat 
 */
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

/**
 * @brief Gets the Starlink payload as a string.
 * 
 * @return string 
 */
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

/**
 * @brief Displays the Starlink payload to the user.
 * 
 */
void Starlink::printPayload() {
	cout<<getPayloadDescription()<<endl;
}

