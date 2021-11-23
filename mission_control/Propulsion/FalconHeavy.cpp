#include <exception>
using namespace std;

#include "FalconHeavy.h"

Propulsion* FalconHeavy::clone() {
	return Booster::clone();
}

void FalconHeavy::operation()
{
	throw "Not yet implemented";
}

string FalconHeavy::getName()
{
	return "Falcon Heavy - " + to_string(this->getBoosterId());
}