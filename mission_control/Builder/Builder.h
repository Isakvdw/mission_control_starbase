#include <exception>
#include <string>
using namespace std;

#ifndef __Builder_h__
#define __Builder_h__

#include "../Rocket.h"
#include "../Propulsion/Booster.h"

/**
 * @brief Interface for a basic rocket builder class
 * @note 
 * 		- Abstract class
 */
class Builder
{
	/// The type of the rocket
	protected: Rocket::RocketType _rocketType;

	/**
	 * @brief This methods returns the rocket that was built
	 * @return A pointer to the rocket that was built
	 * @details see the children class for implementation details
	 */
	public: virtual Rocket* buildRocket() = 0;

	/**
	 * @brief Getter for the rocket type
	 * @return @p _rocketType - A  that is equal to the rockets type
	 */
	public: Rocket::RocketType getRocketType();

	/**
	 * @brief Setter for the rocket type
	 * @param aRocketType The type of the rocket
	 */
	public: void setRocketType(Rocket::RocketType aRocketType);

	/**
	 * @brief Sets the second stage of the rocket
	 * @details See children classess for implementation details
	 */
	public: virtual void setSecondStage()=0;

	/**
	 * @brief Adder for the first stage of the rocket
	 * @details See the the children classes for implementation details
	 */
	public: virtual void setFirstStageBoosters()=0;

	/**
	 * @brief Setter for the payload of the rocket being built
	 * @param aPayload - The payload to add to the rocket
	 * @details See children classes for implementation details
	 */
	public: virtual void setPayload(Payload* aPayload)=0;
};

#endif
