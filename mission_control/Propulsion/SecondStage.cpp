#include <exception>
using namespace std;

#include "SecondStage.h"

void SecondStage::operation()
{
	throw "Not yet implemented";
}

Propulsion* SecondStage::clone() {
	return Booster::clone();
}

#include <iostream>
SecondStage::~SecondStage() {
	for (auto it = _children.begin(); it < _children.end(); it++) {
		delete *it;
	}
	cout << "SeconStage\n";
}

string SecondStage::getName()
{
	return "Second Stage - " + to_string(this->getBoosterId());
}