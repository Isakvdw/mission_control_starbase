#include <exception>
#include <vector>
using namespace std;

#ifndef __Booster_h__
#define __Booster_h__

#include "Propulsion.h"

// class Propulsion;
class Booster;
/**
 * @brief Booster class, child of Propulsion
 * @author Jonathan Enslin - u19103345
 */
class Booster: public Propulsion
{
	/// Children in the composite structure
	private: vector<Propulsion*> _children;
	/// LOX Fuel level as a percentage
	private: int _lOXfuelLevel;
	/// RP1 Fuel level as a percentage
	private: int _rP1fuelLevel;

	/**
	 * @brief adds a propulsion object to the composite structure
	 * @param[in] aP the propulsion object to add to the composite
	 * @details @p aP will be to the vector of propulsion objects
	 */
	public: void add(Propulsion* aP);

	/**
	 * @brief removes a propulsion object
	 * @param aP Propulsion object to be removed
	 * @details This will @p aP from the @p _children vector
	 */
	public: void remove(Propulsion* aP);
	
	/**
	 * @brief Getter for the LOXfuelLevel
	 * @return the LOX fuel level value
	 */
	public: int getLOXfuelLevel();

	/**
	 * @brief Sets the LOX fuel level
	 * @param[in] aLOXfuelLevel The value LOX fuel level should be set to
	 */
	public: void setLOXfuelLevel(int aLOXfuelLevel);

	/**
	 * @brief Getter for the RP1 fuel level
	 * @return RP1 fuel level
	 */
	public: int getRP1fuelLevel();

	/**
	 * @brief Setter for the RP1 fuel level
	 * 
	 */
	public: void setRP1fuelLevel(int aRP1fuelLevel);

	/// @todo find out what this is
	public: virtual void operation();
};

#endif
