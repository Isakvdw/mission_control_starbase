#include <exception>
#include <iostream>
#include <string>
#include <iostream>
using namespace std;

#include "DragonCrew.h"
#include "Payload.h"

/**
 * @brief Construct a new Dragon Crew:: Dragon Crew object
 * 
 */
DragonCrew::DragonCrew() {
	this->_payloadDescription = "Cargo and Crew to be transported to the ISS!";
}

/**
 * @brief Construct a new Dragon Crew:: Dragon Crew object
 * 
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
 * 
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

/**
 * @brief Gets the description of the DragonCrew payload as a string.
 * 
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
 * 
 */
void DragonCrew::printPayload() {
	cout<<getPayloadDescription()<<endl;
}

