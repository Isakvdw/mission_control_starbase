#include <exception>
#include <iostream>
#include <string>
using namespace std;

#include "DragonCrew.h"
#include "Payload.h"

DragonCrew::DragonCrew(const DragonCrew& obj) {
	for (int x = 0; x < 7; x++)
	{
		this->crew[x] = obj.crew[x];
	}
	this->_payloadDescription = obj._payloadDescription;
}

void DragonCrew::insertCrew(string Name, string Rank) {
	for(int x = 0; x < 7; x++)
	{
		if (crew[x] == "")
		{
			crew[x] = Name + ":" + Rank;
			cout<<crew[x]<<", added to launch successfully!"<<endl;
			return;
		}
	}
	cout<<"No more space for launch!"<<endl;
	return;
}

string DragonCrew::getPayloadDescription() {
	bool b = false;
	string out = "Crew members:\n";
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

void DragonCrew::printPayload() {
	cout<<getPayloadDescription()<<endl;
}

