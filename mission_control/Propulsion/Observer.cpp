#include <exception>
#include <string>
using namespace std;

#include "../Observer.h"
#include "../Propulsion.h"


void Observer::setName(string aName) {
	_observerName = aName;
}

void Observer::update() {
	throw "Not yet implemented";
}

