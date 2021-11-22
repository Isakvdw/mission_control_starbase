#include <exception>
#include <vector>
using namespace std;

#include "Propulsion.h"

void Propulsion::add(Propulsion* aP) {
	throw "Not yet implemented";
}

void Propulsion::remove(Propulsion* aP) {
	throw "Not yet implemented";
}

void Propulsion::operation() {
	throw "Not yet implemented";
}

void Propulsion::attach(Observer* aO) {
	_observerList.push_back(aO);
}

void Propulsion::detach(Observer* aO) {
	for(auto it = _observerList.begin(); it < _observerList.end(); it++) {
		if (*it == aO) _observerList.erase(it);
	}
}

void Propulsion::notify() {
	for (auto observer : _observerList) {
		observer->update();
	}
}

