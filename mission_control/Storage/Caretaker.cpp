#include <exception>
using namespace std;

#include "Caretaker.h"

Iterator* Caretaker::createIterator() {
	return _mementos->createIterator();
}

void Caretaker::batchStore(RocketAggregate* aBatch) {
	delete _mementos;
	_mementos = aBatch;
}

void Caretaker::storeRocket(RocketMemento* rockMem) {
	_mementos->add(rockMem);
}

void Caretaker::removeLast() {
	_mementos->remove(_intIter->End());
}

RocketMemento* Caretaker::RestoreLast() {
	return _intIter->End();
}


Caretaker::Caretaker() {
	_mementos = new RocketAggregate();
	_intIter = _mementos->createIterator();
}

Caretaker::~Caretaker() {
	delete _mementos;
	delete _intIter;
}
