#include <exception>
#include <list>
using namespace std;

#ifndef __ConcreteBuilder_h__
#define __ConcreteBuilder_h__

#include "../Propulsion/Engine.h"
#include "../Propulsion/Falcon.h"
#include "../Propulsion/FalconHeavy.h"
#include "../Propulsion/SecondStage.h"
#include "../Rocket.h"
#include "Builder.h"

/**
 * @brief Implements @p Builder, constructs Rockets according to a structure
 * @details This class implements the interface of the @p Builder class, it
 * constructs FalconHeavy and Falcon 9 rockets, the structure followed is as
 * follows: SecondStage->(engine,[firstStages[Engines]])
 */
class ConcreteBuilder : public Builder {
  /// The rocket being worked on
 private:
  Rocket* _constructionRocket;

  /// The current second stage of the rocket
 private:
  Booster* _currSecondStage;

  /// A integer value that counts the number of first stage boosters that have
  /// been added
 private:
  int _numFirstStage;

  /**
   * @brief A default constructor
   * @details A default constructor that sets @p secondStageSet to
   * @p false and @p numFirstStage to @p 0
   * It also creates a new rocket with no parts set
   */
 public:
  ConcreteBuilder();

  /**
   * @brief Returns the built rocket
   * @return A pointer to the rocket that has been built
   * @details This method returns a pointer to the rocket that has
   * been constructed.
   */
 public:
  Rocket* buildRocket() override;

  /**
   * @brief Sets the second stage of the rocket
   * @details This function will add a second stage to the rocket,
   * it will also automatically add an engine to the rocket
   */
 public:
  void setSecondStage() override;

  /**
   * @brief Adds a first stage to the Rocket
   * @details This method will add a first stage Booster to the rocket.
   * 	it will also automatically add engines to the rocket
   */
 public:
  void setFirstStageBoosters() override;

  /**
   * @brief sets the payload of the rocket
   * @param[in] aPayload - The payload to be added to the rocket
   * @details This method will add the given payload to the rocket
   * @note
   * 		- If @p NULL is passed to the function the payload will be set to
   * null
   */
 public:
  void setPayload(Payload* aPayload);
};

#endif
