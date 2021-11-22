#include <exception>
#include <string>
using namespace std;

#include "Engine.h"
#include "Propulsion.h"

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

