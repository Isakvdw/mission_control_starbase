#include <exception>
#include <string>
using namespace std;

#ifndef __Payload_h__
#define __Payload_h__

class Payload
{
	public:
		/**
		 * @brief Specifies different payload types
		 * @details - @p CREW specifies that the payload carries crew
		 * 			- @p CARGO specifies that the payload carries cargo
		 * 			- @p STARLINK specifies that the payload carries starlink satellites
		 */
		enum PayloadType {
			CREW, ///< Crew type
			CARGO, ///< Cargo type
			STARLINK ///< Starlink
		};

	protected: string _payloadDescription; 

	public: virtual string getPayloadDescription() = 0;

	public: virtual void printPayload() = 0;

	public: virtual Payload* clone()=0;

	/**
	 * @brief Launches payload
	 * @details See child classes for implementation
	 */
	public: virtual void launchPayload()=0;
};

#endif
