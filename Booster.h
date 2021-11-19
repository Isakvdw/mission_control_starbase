#include <exception>
#include <vector>
using namespace std;

#ifndef __Booster_h__
#define __Booster_h__

#include "Propulsion.h"

// class Propulsion;
class Booster;

class Booster: public Propulsion
{
	private: vector<Propulsion*> _children;
	private: int _lOXfuelLevel;
	private: int _rP1fuelLevel;
	public: Propulsion* _unnamed_Propulsion_;

	public: void add(Propulsion* aP);

	public: void remove(Propulsion* aP);

	public: int getLOXfuelLevel();

	public: void setLOXfuelLevel(int aLOXfuelLevel);

	public: int getRP1fuelLevel();

	public: void setRP1fuelLevel(int aRP1fuelLevel);

	public: virtual void operation();
};

#endif
