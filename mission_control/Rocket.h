
#ifndef __Rocket_h__
#define __Rocket_h__

#include "Propulsion/Propulsion.h"
#include "Payload/Payload.h"
// #include "State/State.h"

class State;

class Rocket
{
	private: Propulsion* _propulsion;
	private: Payload* _payload;
	private: State* _state;

	public: Propulsion* getPropulsion();

	public: void setPropulsion(Propulsion* aPropulsion);

	public: Payload* getPayload();

	public: void setPayload(Payload* aPayload);

	public: State* getState();

	public: void setState(State* aState);
};

#endif
