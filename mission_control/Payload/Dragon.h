#include <exception>
#include <string>
using namespace std;

#ifndef __Dragon_h__
#define __Dragon_h__

#include "Payload.h"

class Dragon: public Payload 
{
	public:
		Dragon(const Dragon& obj);
		Dragon();
		string getPayloadDescription();
		Payload* clone();
		void setPayloadDescription(string aDescription);
	public: 
		void printPayload();
		/**
		 * @brief Launches the payload
		 * 
		 */
		void launchPayload();
};

#endif
