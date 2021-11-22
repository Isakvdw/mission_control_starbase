#include <exception>
using namespace std;

#include "ConcreteBuilder.h"

ConcreteBuilder::ConcreteBuilder() {
	_constructionRocket = nullptr;
	_numFirstStage = 0;
	_currSecondStage = nullptr;
	_seaLevelMerlin.setType("sea-level merlin");
	
}

void ConcreteBuilder::setSecondStage() {
	if (!_constructionRocket) {
		_constructionRocket = new Rocket(); // init rocket on new build
	}
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
		_numFirstStage = 1;
	} else {
		for (int i = 0; i < 3; i++) {
			booster = new FalconHeavy(); 
			for (int i = 0; i < 9; i++) {
				booster->add(_seaLevelMerlin.clone());
			}
		}
		_numFirstStage = 3;
	}
}

void ConcreteBuilder::setPayload(Payload* aPayload) {}

Rocket* ConcreteBuilder::buildRocket() {
 	Rocket* rocket = _constructionRocket;
	_constructionRocket = nullptr;
	_currSecondStage = nullptr;
	_numFirstStage = 0;
	return rocket;
}
