#include <exception>
#include <iostream>
#include <string>
#include <iostream>
using namespace std;

#include "Dragon.h"

/**
 * @brief Construct a new Dragon::Dragon object 
 * @details Create the Dragon payload.
 */
Dragon::Dragon() {
	this->_payloadDescription = "Cargo to be sent to ISS!";
}

/**
 * @brief Construct a new Dragon::Dragon object
 * @details Copy construct from an existing Dragon payload.
 * @param obj 
 */
Dragon::Dragon(const Dragon& obj) {
	this->_payloadDescription = obj._payloadDescription;
}

/**
 * @brief Gets the description of the Dragon payload as a string.
 * @details Every Dragon payload has a preset payload description.
 * 			This function simply returns the description as a string.
 * @return string 
 */
string Dragon::getPayloadDescription() {
	return _payloadDescription;
}

void Dragon::setPayloadDescription(string aDescription) {
	_payloadDescription = aDescription;
}

/**
 * @brief Displays the description of the Dragon payload to the user.
 * @details Every Dragon payload has a preset payload description.
 * 			This function simply takes the string return of getPayloadDescription()
 * 			and gives it to the user.
 */
void Dragon::printPayload() {
	cout<<getPayloadDescription()<<endl;
}

/**
 * @brief clone function for Dragon
 * @return a pointer to payload
*/
Payload* Dragon::clone(){
	return new Dragon(*this);
}
