#include <exception>
#include <string>
using namespace std;

#include "Engine.h"

void Engine::operation() {
	throw "Not yet implemented";
}

Engine::Engine() {
	_engineType = "";
}

Engine::Engine(string aType) {
	_engineType = aType;
}

Engine* Engine::clone() {
	return new Engine(*this);
}

void Engine::setType(string aType) {
	this->_engineType = aType;
}

Engine::Engine(const Engine& eng) {
	this->_engineType = eng._engineType;
}

void Engine::add(Propulsion* aP) {
	// DO NOTHING
}

void Engine::remove(Propulsion* aP) {
	// DO NOTHING
}

void Engine::setLOXfuelLevel(int level){
	// DO NOTHING
}

void Engine::setRP1fuelLevel(int level){
	// DO NOTHING
}

int Engine::getLOXfuelLevel(){
	// DO NOTHING
	return 0;
}

int Engine::getRP1fuelLevel(){
	// DO NOTHING
	return 0;
}
