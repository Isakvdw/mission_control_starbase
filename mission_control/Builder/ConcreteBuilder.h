#include <exception>
using namespace std;

#ifndef __ConcreteBuilder_h__
#define __ConcreteBuilder_h__

// #include "Rocket.h"
#include "Builder.h"

class ConcreteBuilder: public Builder
{

	public: Rocket* buildRocket();
};

#endif
