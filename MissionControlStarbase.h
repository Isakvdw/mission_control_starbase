#include <exception>
using namespace std;

#ifndef __MissionControlStarbase_h__
#define __MissionControlStarbase_h__

// #include "Rocket.h"
// #include "Builder.h"

class Rocket;
class Builder;
class MissionControlStarbase;

class MissionControlStarbase
{
	private: Rocket* _currentRocket;
	private: Builder* _rocketBuilder;

	public: Rocket* construct(Builder* aBuilder);
};

#endif
