
#ifndef __Rocket_h__
#define __Rocket_h__

// #include "Propulsion.h"
// #include "Payload.h"
// #include "MissionControlStarbase.h"
// #include "State.h"

class Propulsion;
class Payload;
class MissionControlStarbase;
class State;
class Rocket;

class Rocket
{
	private: Propulsion* _propulsion;
	private: Payload* _payload;
	private: State* _state;
	public: MissionControlStarbase* _unnamed_MissionControlStarbase_;
	public: Payload* _unnamed_Payload_;
	public: Propulsion* _unnamed_Propulsion_;
	public: State* _unnamed_State_;

	public: Propulsion* getPropulsion();

	public: void setPropulsion(Propulsion* aPropulsion);

	public: Payload* getPayload();

	public: void setPayload(Payload* aPayload);

	public: State* getState();

	public: void setState(State* aState);
};

#endif
