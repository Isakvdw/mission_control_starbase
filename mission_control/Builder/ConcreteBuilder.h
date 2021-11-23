#include <exception>
#include <list>
using namespace std;

#ifndef __ConcreteBuilder_h__
#define __ConcreteBuilder_h__

#include "Builder.h"
#include "../Rocket.h"
#include "../Propulsion/SecondStage.h"
#include "../Propulsion/Engine.h"
#include "../Propulsion/FalconHeavy.h"
#include "../Propulsion/Falcon.h"

/**
 * @brief Implements @p Builder, constructs Rockets according to a structure
 * @details This class implements the interface of the @p Builder class, it constructs
 * 	FalconHeavy and Falcon 9 rockets, the structure followed is as follows:
 *  SecondStage->(engine,[firstStages[Engines]])
 */
class ConcreteBuilder : public Builder
{
	/// The rocket being worked on
private:
	Rocket *_constructionRocket;

	/// The current second stage of the rocket
private:
	Booster *_currSecondStage;

	/// A integer value that counts the number of first stage boosters that have been added
private:
	int _numFirstStage;

	/// An engine that is used for cloning
private:
	Engine _seaLevelMerlin;

	/**
	 * @brief A parameterized constructor
	 * @param aRocketType The type of the rocket
	 * @param aPayloadType The type of the rockets payload
	 * @details A default constructor that sets @p secondStageSet to 
	 * @p false and @p numFirstStage to @p 0
	 * It also creates a new rocket with no parts set
	 */
public:
	ConcreteBuilder(Rocket::RocketType aRocketType, Payload::PayloadType aPayloadType);

	/**
	 * @brief Returns the built rocket
	 * @return A pointer to the rocket that has been built
	 * @details This method returns a pointer to the rocket that has 
	 * been constructed.
	 */
public:
	Rocket *buildRocket() override;

	/**
	 * @brief Sets the second stage of the rocket
	 * @details This function will add a second stage to the rocket,
	 * it will also automatically add an engine to the rocket
	 */
public:
	void setSecondStage() override;

	/**
	 * @brief Sets the payload when using @b CARGO payload type
	 * @param[in] payloadDescription - The payload description to give to the payload 
	 * @details Sets the payload for payload type CARGO, will automatically create payload an initialise with parameters
	 * @note - This functions is only to be used for setting the payload when @p payLoadType is @b CARGO . If it is not this type, the function will throw a @p string
	 */
	virtual void setPayload(string payloadDescription) override;

	/**
     * @brief Set the Payload object when using @b STARLINK payload type
     * @param[in] numSatellites The number of satellits to add to the chain of satellites (chain of responsibilty)
	 * @details This function will create a starlink payload, for @b STARLINK payload type containing the number of satellites specified as a parameter
	 * @note - Only to be used when payload type is @b STARLNK . If it is not this type the function will throw a @p string
     */
	virtual void setPayload(int numSatellites) override;

	/**
     * @brief Set the Payload object when using @b CREW payload type
     * 
     * @param astronauts A vector of astronauts to add to the payload
     * @param ranks A vector of the respective ranks of the astronauts
	 * @details This will create a payload containing the passed astronauts, the vector of ranks should ideally be the same length as the
	 * astronaut array, but differences in length will be ignored
	 * @note - Only to be used when payload type is @b CREW . If it is not this type the function will throw a @p string
     */
	virtual void setPayload(vector<string> astronauts, vector<string> ranks) override;

	/**
	 * @brief Adds a first stage to the Rocket
	 * @details This method will add a first stage Booster to the rocket.
	 * 	it will also automatically add engines to the rocket
	 */
public:
	void setFirstStageBoosters() override;
};

#endif
