#include <exception>
#include <string>
using namespace std;

#ifndef __Payload_h__
#define __Payload_h__

// #include "Rocket.h"

class Rocket;
class Payload;

class Payload
{
	protected: string _payloadDescription;
	public: Rocket* _unnamed_Rocket_;

	public: virtual string getPayloadDescription() = 0;

	public: virtual void printPayload() = 0;
};

#endif
