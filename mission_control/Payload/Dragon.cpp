#include <exception>
#include <iostream>
#include <string>
#include <iostream>
using namespace std;

#include "Dragon.h"
#include "Payload.h"
/**
 * @brief Construct a new Dragon:: Dragon object
 * 
 */
Dragon::Dragon() {
	this->_payloadDescription = "Cargo to be sent to ISS!";
}

/**
 * @brief Construct a new Dragon:: Dragon object
 * 
 * @param obj 
 */
Dragon::Dragon(const Dragon& obj) {
	this->_payloadDescription = obj._payloadDescription;
}

/**
 * @brief Gets the description of the Dragon payload as a string.
 * 
 * @return string 
 */
string Dragon::getPayloadDescription() {
	return _payloadDescription;
}

/**
 * @brief Displays the description of the Dragon payload to the user.
 * 
 */
void Dragon::printPayload() {
	cout<<getPayloadDescription()<<endl;
}

