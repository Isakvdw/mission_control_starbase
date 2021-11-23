#include <exception>
using namespace std;

#include "ConcreteBuilder.h"

ConcreteBuilder::ConcreteBuilder(Rocket::RocketType aRocketType, Payload::PayloadType aPayloadType) {
	_constructionRocket = nullptr;
	_numFirstStage = 0;
	_currSecondStage = nullptr;
	_seaLevelMerlin.setType("sea-level merlin");
	_rocketType = aRocketType;
	_payloadType = aPayloadType;
	
}

void ConcreteBuilder::setSecondStage() {
	if (!_constructionRocket) {
		_constructionRocket = new Rocket(); // init rocket on new build
		_constructionRocket->setState(new BuildS());
		_constructionRocket->getState()->handle(_constructionRocket);
	}
	if (!_currSecondStage) {
		_currSecondStage = new SecondStage();
		_currSecondStage->setBoosterId(0);
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
		booster->setBoosterId(0);
		for (int i = 0; i < 9; i++) { 				// 9 engines
			booster->add(_seaLevelMerlin.clone()); 	// add engines
		}
		_currSecondStage->add(booster); 			// attach booster to second stage
		_numFirstStage = 1; 						// specify only one booster
	} else {
		for (int i = 0; i < 3; i++) {				// 3 boosters
			booster = new FalconHeavy(); 			// falcon heavy booster
			booster->setBoosterId(i);
			for (int j = 0; j < 9; j++) {			// 9 engines
				booster->add(_seaLevelMerlin.clone()); // add engine
			}
			_currSecondStage->add(booster); 			// attach booster to second stage
		}
		_numFirstStage = 3;							//specify 3 boosters
	}
}

void ConcreteBuilder::setPayload(string payloadDescription) {
	/// @todo see if should add
	//if (_payloadType != Payload::CARGO) throw string("IncorrectPayloadType"); 
	if (_constructionRocket->getPayload()) { // if payload already set
		delete _constructionRocket->getPayload();
	}
	Dragon *payload = new Dragon();
	payload->setPayloadDescription(payloadDescription);
	_constructionRocket->setPayload(payload);
}

void ConcreteBuilder::setPayload(vector<string> astronauts, vector<string> ranks) {
	/// @todo see if should add
	//if (_payloadType != Payload::CREW) throw string("IncorrectPayloadType"); 
	if (_constructionRocket->getPayload()) { // if payload is already set
		delete _constructionRocket->getPayload();
	}	
	DragonCrew* crew = new DragonCrew();
	int bound = (astronauts.size() > ranks.size()) ? ranks.size() : astronauts.size(); // get smallest vector
	for (int i = 0; i < bound; i++) {
		crew->insertCrew(astronauts[i], astronauts[i]); // insert crew members
	}
	_constructionRocket->setPayload(crew);
}

void ConcreteBuilder::setPayload(int numSatellites) {
	/// @todo see if should add
	//if (_payloadType != Payload::STARLINK) throw string("IncorrectPayloadType"); 
	if (_constructionRocket->getPayload()) { // if payload is already set
		delete _constructionRocket->getPayload();
	}
	Starlink* link = new Starlink();
	SatelliteFactory factory;
	for (int i = 0; i < numSatellites; i++) {
		link->addSat(factory.createComponent());
	}
	_constructionRocket->setPayload(link);
}



Rocket* ConcreteBuilder::buildRocket() {
 	Rocket* rocket = _constructionRocket;
	_constructionRocket = nullptr;
	_currSecondStage = nullptr;
	_numFirstStage = 0;
	return rocket;
}
