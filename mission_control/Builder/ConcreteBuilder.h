#include <exception>
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
	/// A boolean value that keeps track of whether or not a second stage has been set
	private: bool _secondStageSet;

	/// A integer value that counts the number of first stage boosters that have been added
	private: int _numFirstStage;

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
	 * 	stage
	 */
	public: void setSecondStage(Booster* aSecondStage) override;

};

#endif
