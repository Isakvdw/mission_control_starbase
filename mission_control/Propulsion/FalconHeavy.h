#include <exception>
using namespace std;

#ifndef __FalconHeavy_h__
#define __FalconHeavy_h__

#include "Booster.h"

class FalconHeavy : public Booster
{

public:
	void operation();

public:
	string getName() override;
};

#endif
