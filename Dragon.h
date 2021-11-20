#include <exception>
#include <string>
using namespace std;

#ifndef __Dragon_h__
#define __Dragon_h__

#include "Payload.h"

// class Payload;
class Dragon;

class Dragon: public Payload
{
	Dragon(const Dragon& obj);

	public: string getPayloadDescription();

	public: void printPayload();
};

#endif
