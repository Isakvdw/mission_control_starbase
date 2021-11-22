#include <exception>
#include <vector>
using namespace std;

#include "RocketIterator.h"
#include "RocketMemento.h"
#include "RocketAggregate.h"
#include "Builder.h"
#include "Iterator.h"

RocketMemento* RocketIterator::next() {
	throw "Not yet implemented";
}

bool RocketIterator::end() {
	throw "Not yet implemented";
}

RocketMemento* RocketIterator::start() {
	throw "Not yet implemented";
}

RocketMemento* RocketIterator::getCurr() {
	throw "Not yet implemented";
}

RocketIterator::RocketIterator(RocketAggregate* aRAgg) {
}

