#include <exception>
#include <string>
using namespace std;

#include "Payload.h"

string Payload::getPayloadDescription() {
	return this->_payloadDescription;
}

void Payload::printPayload() {
	throw "Not yet implemented";
}

