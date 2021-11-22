#include <exception>
using namespace std;

#include "ConcreteBuilder.h"

ConcreteBuilder::ConcreteBuilder() {
	_constructionRocket = new Rocket();
	_numFirstStage = 0;
	_currSecondStage = nullptr;
	Engine seaLevelMerlin("sea-level merlin");
}

void ConcreteBuilder::setSecondStage() {
	if (!_currSecondStage) {
		_currSecondStage = new SecondStage();
		_currSecondStage->add(new Engine("merlin-vacuum engine"));
		_constructionRocket->setPropulsion(_currSecondStage);
	}
}

void ConcreteBuilder::addFirstStage() {
	if (!_currSecondStage) setSecondStage();
	if (_numFirstStage < 3) {
		
	}
}

Rocket* ConcreteBuilder::buildRocket() {
	Rocket *rocket = _constructionRocket;
	_constructionRocket = nullptr;
	return rocket;
}



