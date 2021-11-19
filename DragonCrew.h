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

	public: string getPayloadDescription();

	public: void printPayload();
};

#endif
