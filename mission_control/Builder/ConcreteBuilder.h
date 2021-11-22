#include <exception>
using namespace std;

#ifndef __ConcreteBuilder_h__
#define __ConcreteBuilder_h__

// #include "../Rocket.h"
#include "../Builder.h"

class Rocket;
// class Builder;
class ConcreteBuilder;

class ConcreteBuilder: public Builder
{

	public: Rocket* buildRocket();
};

#endif
