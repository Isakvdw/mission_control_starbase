#include <exception>
#include <string>
using namespace std;

#ifndef __Payload_h__
#define __Payload_h__

class Payload
{
	protected: string _payloadDescription;

	public: virtual string getPayloadDescription() = 0;

	public: virtual void printPayload() = 0;
};

#endif
