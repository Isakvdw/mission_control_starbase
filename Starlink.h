#include <exception>
#include <string>
using namespace std;

#ifndef __Starlink_h__
#define __Starlink_h__

// #include "SatelliteLauncher.h"
#include "Payload.h"

class SatelliteLauncher;
// class Payload;
class Starlink;

class Starlink: public Payload
{
	private: SatelliteLauncher* _satellites;
	public: SatelliteLauncher* _unnamed_SatelliteLauncher_;

	public: string getPayloadDescription();

	public: void printPayload();
};

#endif
