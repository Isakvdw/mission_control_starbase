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

	public: string getPayloadDescription();

	public: void printPayload();
};

#endif
