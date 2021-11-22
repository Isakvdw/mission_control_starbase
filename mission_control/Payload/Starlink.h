#include <exception>
#include <string>
using namespace std;

#ifndef __Starlink_h__
#define __Starlink_h__

#include "SatelliteLauncher.h"
#include "Payload.h"

class Starlink: public Payload
{
	private: 
		SatelliteLauncher* _satellites; 
	public: 
		Starlink();
		~Starlink();
		Payload * clone();
		void LaunchAllSatellites(); 
		// SatelliteLauncher* _unnamed_SatelliteLauncher_;
		void addSat(SatelliteLauncher* Sat);
		string getPayloadDescription();
		void printPayload();
};

#endif
