#include <exception>
using namespace std;

#ifndef __Falcon_h__
#define __Falcon_h__

#include "Booster.h"

class Falcon : public Booster
{

public:
	Propulsion* clone();

public:
	void operation();

public:
	string getName() override;
};

#endif
