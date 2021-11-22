#include <exception>
#include <list>
using namespace std;

#ifndef __ConcreteBuilder_h__
#define __ConcreteBuilder_h__

#include "../Rocket.h"
#include "Builder.h"

/**
 * @brief Implements @p Builder, constructs Rockets according to a structure
 * @details This class implements the interface of the @p Builder class, it constructs
 * 	FalconHeavy and Falcon 9 rockets, the structure followed is as follows:
 *  SecondStage->(engine,[firstStages[Engines]])
 */
class ConcreteBuilder: public Builder 
{
	/// The rocket being worked on
	private: Rocket *_constructionRocket;

	/// The current second stage of the rocket
	private: Booster *_currSecondStage;

	/// A boolean value that keeps track of whether or not a second stage has been set
	private: bool _secondStageSet;

	/// A integer value that counts the number of first stage boosters that have been added
	private: int _numFirstStage;

	/// A Buffer for First Stage Boosters and Engines
	private: list<Propulsion *> _propulsionBuffer;

	/**
	 * @brief A default constructor
	 * @details A default constructor that sets @p secondStageSet to 
	 * @p false and @p numFirstStage to @p 0
	 * It also creates a new rocket with no parts set
	 */
	public: ConcreteBuilder();

	/**
	 * @brief Returns the built rocket
	 * @return A pointer to the rocket that has been built
	 * @details This method returns a pointer to the rocket that has 
	 * been constructed.
	 */
	public: Rocket* buildRocket() override;

	/**
	 * @brief Sets the second stage of the rocket
	 * @param[in] aSecondStage - The second stage to add to the rocket
	 * @details This function will set the second stage of the rocket and log
	 * 	that the second stage has been set, if later another second stage is set,
	 * 	it will overwrite the current second stage, adding the new one, if @p NULL
	 * 	is passed it will remove the second stage, and log that there is no second
	 * 	stage, any first stage booster will be added back into the buffer queue
	 * @note 
	 * 		- Any Observer must be attached to the booster before adding it to the rocket.
	 */
	public: void setSecondStage(Booster* aSecondStage) override;

	/**
	 * @brief Adds a first stage to the Rocket
	 * @param[in] aFirstStage - The first stage to be added to the rocket
	 * @details This method will add a first stage Booster to the rocket.
	 * 	It does so by pushing it to the back of the second stage booster,
	 * 	in the case that the Rocket does not yet have a second stage, it will
	 * 	buffer the Booster in a queue, and add it once a second stage has been added
	 * 	it will also update the variable tracking the amount of second stage boosters added.
	 * 	@note 
	 * 		- Any Observer must be attached to the booster before adding it to the rocket.
	 * 		- If @p NULL is passed to the rocket, nothing will be done.
	 */
	public: void addFirstStage(Booster* aFirstStage) override;

	/**
	 * @brief sets the payload of the rocket
	 * @param[in] aPayload - The payload to be added to the rocket
	 * @details This method will add the given payload to the rocket
	 * @note
	 * 		- If @p NULL is passed to the function the payload will be set to null
	 */
	public: void setPayload(Payload* aPayload);

};

#endif
