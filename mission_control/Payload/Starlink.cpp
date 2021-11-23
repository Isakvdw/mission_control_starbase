#include <exception>
#include <iostream>
#include <string>
#include <iostream>
using namespace std;

#include "Starlink.h"
#include "Satellite.h"

/**
 * @brief Construct a new Starlink::Starlink object
 * @details Creates the Starlink payload.
 * 			Presets the payload description accoringly
 * 			and then head of the list is set to NULL.
 */
Starlink::Starlink() {
	this->_payloadDescription = "Cargo of satellites to be released into orbit!";
	this->_satellites = NULL;
}

/**
 * @brief Destroy the Starlink::Starlink object
 * 		  Delete the array of satelliteLaunchers.
 * @details Destructor of Starlink payload.
 * 			Since Starlink used dynamic objects 
 * 			we have to delete each object.
 * 			Call handleRequest() to delete each
 * 			object and nullify all locations.
 */
Starlink::~Starlink() { 
	if (this->_satellites != NULL) { 
		this->_satellites->handleRequest();
		delete this->_satellites;
		this->_satellites = NULL;
		return;
	}
}

void Starlink::launchPayload() {
	cout << "Launching: " << endl << getPayloadDescription();
	cout << endl;
	LaunchAllSatellites();
}

/**
 * @brief Starlink clones itself
 * @details Starlink clones itself and makes a brand new 
 * 			Starlink with all the same variables that 
 * 			are not shallow copied.
 * @return Starlink* 
 */
Payload* Starlink::clone() {
	int CT = this->_satellites->count();
	Starlink * SL = new Starlink();
	for (int x = 0; x < CT; x++)
	{
		SL->addSat(new Satellite());
	}
	return SL;
}

/**
 * @brief Simulates the the ejection by calling the head Satellite
 *		  to Handle the request which goes down the chain deleting and
 *        detaching satellites.
 * @details Simulates the launch of all Satellites by calling
 * 			handleRequest(), but with the added functionality
 * 			of checking whether satellites exist or not.
 * 			This empties the payload of satellites and 
 * 			detaches aswell as deletes each object. 
 * 			Displays to the user whether or not
 * 			Satellites released or not. 
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
 * @details Add satellites to the chain.
 * 			With use of recursion the addition
 * 			goes down the chain until free position
 * 			is taken.
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
 * @details Makes a string of the description with use of
 * 			some count() to find the current number of 
 * 			Satellites. 
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
 * @details Calls getPayloadDescription() and takes the 
 * 			already structured string to display to the
 * 			user.
 */
void Starlink::printPayload() {
	cout<<getPayloadDescription()<<endl;
}

