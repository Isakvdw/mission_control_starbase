
#ifndef __RocketMemento_h__
#define __RocketMemento_h__

// #include "Caretaker.h"
// #include "Aggregate.h"

class Caretaker;
class Aggregate;
class RocketMemento;

class RocketMemento
{
	private: string _rocket_state;
	public: Caretaker* _unnamed_Caretaker_;
	public: Aggregate* _unnamed_Aggregate_;
};

#endif
