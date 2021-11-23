#include <exception>
using namespace std;

#ifndef __SecondStage_h__
#define __SecondStage_h__

#include "Booster.h"

class SecondStage : public Booster
{

public:
	Propulsion* clone();

public:
	void operation();

public:
	string getName() override;

public:
    /**
     * @brief Get the Child Booster object
     * @details Gets a booster from the child, taken from children[index + 1], thus skipping over engine
     * @param index The index of the child booster to obtain
     * @return Booster* 
	 * @note - This should only be used on a a Rocket/Booster that adheres to the structure made by a @p ConcreteBuilder
     */
	Booster* getChildBooster(int index) override;

};

#endif
