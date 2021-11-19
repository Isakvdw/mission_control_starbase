#include <exception>
using namespace std;

#ifndef __SateliteLauncher_h__
#define __SateliteLauncher_h__

// #include "Starlink.h"

class Starlink;
class SateliteLauncher;

class SateliteLauncher
{
	private: SatelliteLauncher* _successor;
	public: Starlink* _unnamed_Starlink_;
	public: SateliteLauncher* _unnamed_SateliteLauncher_;

	public: void handleRequest();
};

#endif
