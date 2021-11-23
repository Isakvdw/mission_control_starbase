#include <exception>
using namespace std;

#ifndef __SatelliteLauncher_h__
#define __SatelliteLauncher_h__ 

class SatelliteLauncher
{
	protected: 
		SatelliteLauncher* _successor;
	public: 
		// Starlink* _unnamed_Starlink_;
		// SatelliteLauncher* _unnamed_SatelliteLauncher_;
		SatelliteLauncher();
		~SatelliteLauncher();
		virtual void handleRequest(int number = 0)=0;
		void add(SatelliteLauncher* satellite); 
		int count();
};

#endif
