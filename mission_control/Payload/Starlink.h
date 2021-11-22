#include <exception>
#include <string>
using namespace std;

#ifndef __Starlink_h__
#define __Starlink_h__

#include "SatelliteLauncher.h"
#include "Payload.h"

class SatelliteLauncher;
class Payload;
class Starlink;

class Starlink: public Payload
{
	private: 
		SatelliteLauncher* _satellites; 
	public: 
		Starlink();
		~Starlink(); 
		void LaunchAllSatellites();
		// SatelliteLauncher* _unnamed_SatelliteLauncher_;
		void addSat(SatelliteLauncher* Sat);
		string getPayloadDescription();
		void printPayload();
};

#endif
