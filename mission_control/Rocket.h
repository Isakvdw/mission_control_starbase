
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

	public:
		/**
		 * @brief Specifies the type of 
		 * @details 
		 * 		@p FALCON9 Rockets will have 1 first stage boosters
		 * 		@p FALCONHEAVY Rockets will have 3 first stage boosters	
		 */
		enum RocketType {
				FALCON9,     ///< Specifies that the rocket is a Falcon-9 Rocket
				FALCONHEAVY  ///< Specifies that the rocket is a Falcon Heavy Rocket
			};

	public: Propulsion* getPropulsion();

	public: void setPropulsion(Propulsion* aPropulsion);

	public: Payload* getPayload();

	public: void setPayload(Payload* aPayload);

	public: State* getState();

	public: void setState(State* aState);
};

#endif
