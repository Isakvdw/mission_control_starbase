#include <exception>
using namespace std;

#ifndef __SatelliteLauncher_h__
#define __SatelliteLauncher_h__

class SatelliteLauncher
{
	private: 
		SatelliteLauncher* _successor;
	public: 
		// Starlink* _unnamed_Starlink_;
		// SatelliteLauncher* _unnamed_SatelliteLauncher_;
		SatelliteLauncher();
		void handleRequest();
		void add(SatelliteLauncher* satellite); 
		int count();
};

#endif
