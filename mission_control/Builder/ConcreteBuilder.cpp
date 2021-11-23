#include <exception>
using namespace std;

#include "ConcreteBuilder.h"

ConcreteBuilder::ConcreteBuilder(Rocket::RocketType aRocketType, Payload::PayloadType aPayloadType) {
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
	if (_numFirstStage != 0) return;
	if (_rocketType == Rocket::FALCON9) {
		booster = new Falcon(); 					// only one booster
		for (int i = 0; i < 9; i++) { 				// 9 engines
			booster->add(_seaLevelMerlin.clone()); 	// add engines
		}
		_currSecondStage->add(booster); 			// attach booster to second stage
		_numFirstStage = 1; 						// specify only one booster
	} else {
		for (int i = 0; i < 3; i++) {				// 3 boosters
			booster = new FalconHeavy(); 			// falcon heavy booster
			for (int i = 0; i < 9; i++) {			// 9 engines
				booster->add(_seaLevelMerlin.clone()); // add engine
			}
		}
		_numFirstStage = 3;							//specify 3 boosters
	}
}

void ConcreteBuilder::setPayload(string payloadDescription) {
	if (_payloadType != Payload::CARGO) throw string("IncorrectPayloadType"); 
	
}

Rocket* ConcreteBuilder::buildRocket() {
 	Rocket* rocket = _constructionRocket;
	_constructionRocket = nullptr;
	_currSecondStage = nullptr;
	_numFirstStage = 0;
	return rocket;
}
