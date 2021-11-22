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

	/**
	 * @brief Creates a clone of the engine
	 * @return Pointer to the clone of this engine
	 */
	public: Engine* clone();

	/**
	 * Default constructor for Engine, sets type to an empty string
	 */
	public: Engine();

	/**
	 * @brief Parameterized constructor
	 * @param[in] aType the type of the engine
	 */
	public: Engine(string aType);

	/// Copy constructor
	public: Engine(const Engine& eng); // Copy constructor added

	/**
	 * @brief Sets the type of the engine
	 * @param[in] aType The type of the rocket
	 */
	public: void setType(string aType);

	/// Does nothing
	public: virtual void add(Propulsion* aP);
	
	/// Does nothing
	public: virtual void remove(Propulsion* aP);
};

#endif
