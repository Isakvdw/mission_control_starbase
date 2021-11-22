#include <exception>
using namespace std;

#include "SecondStage.h"

void SecondStage::operation()
{
	throw "Not yet implemented";
}

string SecondStage::getName()
{
	return "Second Stage - " + to_string(this->getBoosterId());
}