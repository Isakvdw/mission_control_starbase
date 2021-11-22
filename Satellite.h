#include <exception>
using namespace std;

#ifndef __Satellite_h__
#define __Satellite_h__

#include "SatelliteLauncher.h" 

// class SatelliteLauncher;
class Satellite;

class Satellite: public SatelliteLauncher
{
	public: 
		Satellite();
		Satellite(const Satellite& obj);
		Satellite* clone();
};

#endif
