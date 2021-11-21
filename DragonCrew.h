#include <exception>
#include <string>
using namespace std;

#ifndef __DragonCrew_h__
#define __DragonCrew_h__

#include "Payload.h"

// class Payload;
class DragonCrew;

class DragonCrew: public Payload
{
	private:
		string crew[7] = {"","","","","","",""};
		const int CREWCAP = 7;
	public: 
		DragonCrew();
		DragonCrew(const DragonCrew& obj);
		void insertCrew(string Name, string Rank);
		string getPayloadDescription();
	public: 
		void printPayload();
};

#endif
