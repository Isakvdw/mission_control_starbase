#include <exception>
using namespace std;

#include "Satellite.h"
// #include "SatelliteLauncher.h"

Satellite::Satellite(const Satellite& obj) {}

Satellite* Satellite::clone() {
	return new Satellite(*this);
}

