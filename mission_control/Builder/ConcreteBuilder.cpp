#include <exception>
using namespace std;

#include "ConcreteBuilder.h"

ConcreteBuilder::ConcreteBuilder() {
	_constructionRocket = new Rocket();
	_numFirstStage = 0;
	_currSecondStage = nullptr;
	_seaLevelMerlin.setType("sea-level merlin");
	
}

void ConcreteBuilder::setSecondStage() {
	if (!_currSecondStage) {
		_currSecondStage = new SecondStage();
		_currSecondStage->add(new Engine("merlin-vacuum engine"));
		_constructionRocket->setPropulsion(_currSecondStage);
	}
}

void ConcreteBuilder::setFirstStageBoosters() {
	if (!_currSecondStage) setSecondStage();
	Booster* booster;
	if (_rocketType == Rocket::FALCON9) {
		booster = new Falcon(); 
		for (int i = 0; i < 9; i++) {
			booster->add(_seaLevelMerlin.clone());
		}
		_currSecondStage->add(booster);
	} else {
		for (int i = 0; i < 3; i++) {
			booster = new FalconHeavy(); 
			for (int i = 0; i < 9; i++) {
				booster->add(_seaLevelMerlin.clone());
			}
		}
	}
}

void ConcreteBuilder::setPayload(Payload* aPayload) {}

Rocket* ConcreteBuilder::buildRocket() {
	Rocket *rocket = _constructionRocket;
	_constructionRocket = nullptr;
	return rocket;
}



