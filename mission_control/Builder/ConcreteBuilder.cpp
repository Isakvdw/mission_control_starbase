#include <exception>
using namespace std;

#include "ConcreteBuilder.h"

ConcreteBuilder::ConcreteBuilder() {
<<<<<<< HEAD
	_constructionRocket = new Rocket();
	_numFirstStage = 0;
	_currSecondStage = nullptr;
	_seaLevelMerlin.setType("sea-level merlin");
	
=======
  _constructionRocket = new Rocket();
  _numFirstStage = 0;
  _currSecondStage = nullptr;
  Engine seaLevelMerlin("sea-level merlin");
>>>>>>> 05dd851ad53e49f6665f8a58b452c87a225789bb
}

void ConcreteBuilder::setSecondStage() {
  if (!_currSecondStage) {
    _currSecondStage = new SecondStage();
    _currSecondStage->add(new Engine("merlin-vacuum engine"));
    _constructionRocket->setPropulsion(_currSecondStage);
  }
}

void ConcreteBuilder::setFirstStageBoosters() {
<<<<<<< HEAD
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
=======
  if (!_currSecondStage) setSecondStage();
  if (_rocketType == Rocket::FALCON9) {
    // Fa
  }
>>>>>>> 05dd851ad53e49f6665f8a58b452c87a225789bb
}

void ConcreteBuilder::setPayload(Payload* aPayload) {}

Rocket* ConcreteBuilder::buildRocket() {
  Rocket* rocket = _constructionRocket;
  _constructionRocket = nullptr;
  return rocket;
}
