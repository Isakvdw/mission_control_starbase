#include <exception>
using namespace std;

#include "SecondStage.h"

void SecondStage::operation()
{
	throw "Not yet implemented";
}

Propulsion* SecondStage::clone() {
	return new SecondStage();
}

string SecondStage::getName()
{
	return "Second Stage - " + to_string(this->getBoosterId());
}