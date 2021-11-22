#include <exception>
#include <string>
using namespace std;

#ifndef __Builder_h__
#define __Builder_h__

#include "../Payload/Payload.h"
#include "../Payload/SatelliteFactory.h"
#include "../Propulsion/Booster.h"
#include "../Rocket.h"

/**
 * @brief Interface for a basic rocket builder class
 * @note
 * 		- Abstract class
 */
class Builder {
   protected:
    /// The type of the rocket
    Rocket::RocketType _rocketType;

    /// The type of the payload
    Payload::PayloadType _payloadType;

   public:
    /**
   * @brief This methods returns the rocket that was built
   * @return A pointer to the rocket that was built
   * @details see the children class for implementation details
   */
    virtual Rocket* buildRocket() = 0;

    /**
   * @brief Getter for the rocket type
   * @return @p _rocketType - A  that is equal to the rockets type
   */
    Rocket::RocketType getRocketType();

    /**
   * @brief Setter for the rocket type
   * @param aRocketType The type of the rocket
   */
    void setRocketType(Rocket::RocketType aRocketType);

    /**
    * @brief Sets the second stage of the rocket
    * @details See children classess for implementation details
    */
    virtual void setSecondStage() = 0;

    /**
     * @brief Adder for the first stage of the rocket
     * @details See the the children classes for implementation details
     */
    virtual void setFirstStageBoosters() = 0;

    /// see child class for details
    virtual void setPayload(string payloadDescription) = 0;
  
    /// see child class for details
    virtual void setPayload(int numSatellites) = 0;
    
    /// see child class for details
    virtual void setPayload(vector<string> astronauts) = 0;

    /**
     * @brief Setter for the payload type of the rocket being built
     * @param[in] aPayload - The payload type to be produced
     */
    virtual void setPayloadType(Payload::PayloadType aPayloadType);
};

#endif