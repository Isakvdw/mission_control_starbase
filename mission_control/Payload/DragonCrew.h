#include <exception>
#include <string>
using namespace std;

#ifndef __DragonCrew_h__
#define __DragonCrew_h__

#include "Payload.h"

class DragonCrew: public Payload 
{
	private:
		string crew[7] = {"","","","","","",""};
		const int CREWCAP = 7;
	public: 
		DragonCrew(const DragonCrew& obj);
		DragonCrew();
		void insertCrew(string Name, string Rank);
		string getPayloadDescription();
	public: 
		void printPayload();
};

#endif
