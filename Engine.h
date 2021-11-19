#include <exception>
#include <string>
using namespace std;

#ifndef __Engine_h__
#define __Engine_h__

#include "Propulsion.h"

// class Propulsion;
class Engine;

class Engine: public Propulsion
{
	private: string _engineType;

	public: void operation();

	public: Engine* clone();

	public: Engine(const Engine& eng); // Copy constructor added

	public: void setType(string aType);

	public: virtual void add(Propulsion* aP);

	public: virtual void remove(Propulsion* aP);
};

#endif
