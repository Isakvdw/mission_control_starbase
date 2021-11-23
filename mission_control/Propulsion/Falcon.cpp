#include <exception>
using namespace std;

#include "Falcon.h"

void Falcon::operation()
{
	throw "Not yet implemented";
}

string Falcon::getName()
{
	return "Falcon - " + to_string(this->getBoosterId());
}

Propulsion* Falcon::clone() {
	return Booster::clone();
}