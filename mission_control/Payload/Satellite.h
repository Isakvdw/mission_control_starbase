#include <exception>
using namespace std;

#ifndef __Satellite_h__
#define __Satellite_h__

#include "SatelliteLauncher.h"  

class Satellite: public SatelliteLauncher
{
	public: 
		Satellite();
		Satellite(const Satellite& obj);
		Satellite* clone();
		void satBoot(int v);
		
		/**
		 * @brief SatelliteLauncher goes down the chain of Satellites.
		 * Once it reaches the end they detach and delete. 
		 * @details Once handleRequest() is called.
		 * 			Starting from the head the list of Satellites is
		 * 			traversed until the very end.
		 * 			At the end through recursion the ends get deleted 
		 */
		void handleRequest(int number = 0);
};

#endif
