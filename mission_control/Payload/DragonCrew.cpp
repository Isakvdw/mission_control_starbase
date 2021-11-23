#include <exception>
#include <iostream>
#include <string>
#include <iostream>
using namespace std;

#include "DragonCrew.h"

/**
 * @brief Construct a new DragonCrew::DragonCrew object 
 * @details Every DragonCrew payload has a preset payload description.
 * 			This function simply returns the description as a string.
 * 			DragonCrew has a permanent 7 size for 7 crew members.
 */
DragonCrew::DragonCrew() {
	this->_payloadDescription = "Cargo and Crew to be transported to the ISS!";
}

/**
 * @brief Copy constructor for a new DragonCrew::DragonCrew object
 * @details Every DragonCrew payload has a preset payload description.
 * 			The crew member array is then copied over to the new DragonCrew.
 * 			Then the description is copied aswell.
 * @param obj 
 */
DragonCrew::DragonCrew(const DragonCrew& obj) {
	for (int x = 0; x < 7; x++)
	{
		this->crew[x] = obj.crew[x];
	}
	this->_payloadDescription = obj._payloadDescription;
}

/**
 * @brief Insert a crew member into the DragonCrew object.
 * @details When inserting into the array. "" represents empty places.
 * 			We use this to add crew members in line with their Name and Rank.
 * 			Displays a message if the insertion was successful or 
 * 			a other message if payload is full.
 * @param Name 
 * @param Rank 
 */
void DragonCrew::insertCrew(string Name, string Rank) {
	for(int x = 0; x < 7; x++)
	{
		if (crew[x] == "")
		{
			crew[x] = Name + " : " + Rank;
			cout<<crew[x]<<", added to launch successfully!"<<endl;
			return;
		}
	}
	cout<<"No more space for launch!"<<endl;
	return;
}

void DragonCrew::launchPayload() {
	cout << "Launching Astronauts: " << endl;
	cout << getPayloadDescription() << endl;
	for (int i = 0; i < CREWCAP; i++) {
		crew[i] = "";
	}
	cout << "Astronauts Launched" << endl;
}

/**
 * @brief Gets the description of the DragonCrew payload as a string.
 * @details Builds a description string from the given info.
 * 			Builds the list of crew members.
 * 			Then adds the description to the out string.
 * @return string 
 */
string DragonCrew::getPayloadDescription() {
	bool b = false;
	string out = "Crew members : \n";
	for(int x = 0; x < 7; x++)
	{
		if (crew[x] != "")
		{	
			b = true;
			out = out + "\t"+crew[x]+"\n";
		}
	}
	if (!b)
	{
		out = out + "\tNo crew members!\n";
	}
	out = out + "\n";
	out = out + _payloadDescription;
	return out;
}

/**
 * @brief Displays the DragonCrew payload to the user.
 * @details Calls getPayloadDescription() to receive the out string.
 * 			The string is built with tabs and newlines for output.
 * 			The string is displayed to the user.
 */
void DragonCrew::printPayload() {
	cout<<getPayloadDescription()<<endl;
}

/**
 * @brief A clone for the dragon crew
 * @return A Payload Pointer
*/

Payload* DragonCrew::clone(){
	return new DragonCrew(*this);
}