#include <exception>
using namespace std;

#ifndef __SatelliteLauncher_h__
#define __SatelliteLauncher_h__

// #include "Starlink.h"

class Starlink;
class SatelliteLauncher;

class SatelliteLauncher
{
	private: SatelliteLauncher* _successor;
	public: Starlink* _unnamed_Starlink_;
	public: SatelliteLauncher* _unnamed_SatelliteLauncher_;

	public: void handleRequest();
};

#endif
