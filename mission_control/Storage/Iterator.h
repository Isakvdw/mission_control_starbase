#include <exception>
using namespace std;

#ifndef __Iterator_h__
#define __Iterator_h__

// #include "Caretaker.h"
// #include "RocketMemento.h"

class Caretaker;
class RocketMemento;
class Iterator;

class Iterator
{
	public: Caretaker* _unnamed_Caretaker_;

	public: virtual RocketMemento* next() = 0;

	public: virtual bool end() = 0;

	public: virtual RocketMemento* start() = 0;

	public: RocketMemento* getCurr();
};

#endif
