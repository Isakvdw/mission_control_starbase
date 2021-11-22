#include <exception>
#include <string>
using namespace std;

#ifndef __Builder_h__
#define __Builder_h__

// #include "MissionControlStarbase.h"
// #include "RocketIterator.h"
// #include "Rocket.h"

class MissionControlStarbase;
class RocketIterator;
class Rocket;
class Builder;

class Builder
{
	private: string _rocketType;

	public: virtual Rocket* buildRocket() = 0;

	public: string getRocketType();

	public: void setRocketType(string aRocketType);
};

#endif
