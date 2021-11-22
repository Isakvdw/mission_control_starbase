#include <exception>
#include <vector>
using namespace std;

#ifndef __RocketIterator_h__
#define __RocketIterator_h__

// #include "../RocketMemento.h"
// #include "../RocketAggregate.h"
// #include "../Builder.h"
#include "../Iterator.h"

class RocketMemento;
class RocketAggregate;
class Builder;
// class Iterator;
class RocketIterator;

class RocketIterator: public Iterator
{
	private: vector<RocketMemento*>* _curr;
	public: RocketAggregate* _unnamed_RocketAggregate_;
	public: Builder* _unnamed_Builder_;

	public: RocketMemento* next();

	public: bool end();

	public: RocketMemento* start();

	public: RocketMemento* getCurr();

	public: RocketIterator(RocketAggregate* aRAgg);
};

#endif
