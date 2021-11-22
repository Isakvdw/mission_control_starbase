#include <exception>
#include <iostream>
#include <string>
#include <iostream>
using namespace std;

#include "Dragon.h"
#include "Payload.h"

Dragon::Dragon() {
	this->_payloadDescription = "Cargo to be sent to ISS!";
}

Dragon::Dragon(const Dragon& obj) {
	this->_payloadDescription = obj._payloadDescription;
}

string Dragon::getPayloadDescription() {
	return _payloadDescription;
}

void Dragon::printPayload() {
	cout<<getPayloadDescription()<<endl;
}

