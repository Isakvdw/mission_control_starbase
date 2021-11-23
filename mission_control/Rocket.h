
#ifndef __Rocket_h__
#define __Rocket_h__

#include "Propulsion/Propulsion.h"
#include "Payload/Payload.h"
#include "Storage/StorageG.h"
// #include "State/State.h"
#include "Propulsion/Booster.h"

class State;
class RocketMemento;

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

	private: RocketType _rocketType;
	
	public: Rocket();

	public:
	/**
	 * @brief Get the Second Stage object
	 * @details Returns a pointer to the second stage of the rocket
	 * @return SecondStage* 
	 */
	Booster* getSecondStage();

	public:
	/**
	 * @brief Get the First Stage object at a certain index
	 * @details Returns the index'th first stage booster 
	 * @param index 
	 * @return Booster* 
	 */
	Booster* getFirstStage(int index);

	/// 
	public: RocketType getRocketType();

	/**
	 * @brief Sets the rocket type
	 * @note - This should not be changed after rocket has been created
	 * @param[in] type The type of the rocket 
	 */
	public: void setRocketType(RocketType type);

	/// Returns the propulsion object of the rocket
	public: Propulsion* getPropulsion();

	/// sets the propulsion object of the rocket
	public: void setPropulsion(Propulsion* aPropulsion);

	/// gets the rocket's payload
	public: Payload* getPayload();

	/// sets the rocket's payload
	public: void setPayload(Payload* aPayload);

	/// gets the state object of the rocket
	public: State* getState();

	/// sets the state object of the rocket
	public: void setState(State* aState);

	public: virtual ~Rocket();

	public: RocketMemento* Save();

	public: void Restore(RocketMemento* aRockMem);
};

#include "State/State.h"

#endif
