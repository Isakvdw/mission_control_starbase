#include <exception>
#include <string>
using namespace std;

#include "Dragon.h"
#include "Payload.h"

Dragon::Dragon(const Dragon& obj) {
	this->_payloadDescription = obj._payloadDescription;
}

string Dragon::getPayloadDescription() {
	return _payloadDescription;
}

void Dragon::printPayload() {
	cout<<getPayloadDescription()<<endl;
}

