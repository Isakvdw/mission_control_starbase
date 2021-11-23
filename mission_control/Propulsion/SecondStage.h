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
	~SecondStage() override;
};

#endif
