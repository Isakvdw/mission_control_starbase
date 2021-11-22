#include "RocketMemento.h"
#include "Caretaker.h"
#include "Aggregate.h"

RocketMemento::RocketMemento(string s) : _rocket_state(s) {}

string RocketMemento::getRocketState()
{
  return _rocket_state;
}
