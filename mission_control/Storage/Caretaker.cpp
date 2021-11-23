#include <exception>
using namespace std;

#include "Caretaker.h"

Iterator* Caretaker::createIterator() {
	return _mementos->createIterator();
}

void Caretaker::batchStore(RocketAggregate* aBatch) {
	delete _mementos;
	_mementos = aBatch;
	_intIter = _mementos->createIterator();
}

void Caretaker::batchRun() {
	_intIter->start();
	RocketMemento* curr = _intIter->getCurr();
	Rocket* temp = new Rocket();
	cout << "+++++BATCH RUN+++++" << endl;
	while (!_intIter->isEnd()) {
		cout << "--------------------------" << endl;
		temp->setPayload(curr->getPayload());
		temp->setPropulsion(curr->getPropulsion());
		temp->setState(curr->getState());
		temp->setRocketType(curr->getType());
		MCS->launch(temp);
		curr = _intIter->next();
		cout << "--------------------------" << endl;

	}
	delete temp;	
	cout << "+++++++++++++++++++++++" << endl;
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
