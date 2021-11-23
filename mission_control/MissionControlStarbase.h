#include <exception>
using namespace std;

#ifndef __MissionControlStarbase_h__
#define __MissionControlStarbase_h__

#include "Rocket.h"
#include "Builder/Builder.h"

class MissionControlStarbase
{
	private: Rocket* _currentRocket;
	private: Builder* _rocketBuilder;

	public: Rocket* construct(Builder* aBuilder);

	public: void launch(Rocket* R);
};

#endif
