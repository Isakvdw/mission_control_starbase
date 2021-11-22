#include <exception>
#include <string>
using namespace std;

#ifndef __FuelObserver_h__
#define __FuelObserver_h__

// #include "../Booster.h"
#include "../Observer.h"

class Booster;
// class Observer;
class FuelObserver;
/**
 * @brief A class that observers fuel
 * @author Jonathan Enslin - u19103345
 */
class FuelObserver: public Observer
{
	/// @brief Stores the latest updated fuel level of observed objects LOXfuel level
	private: int _lOXfuelState;
	/// @brief Stores the latest updated fuel level of observed objects RP1fuel level
	private: int _rP1fuelState;
	/// @brief Pointer to the Booster being observed
	private: Booster* _concreteBooster;

	/**
	 * Default constructor for FuelObserver, sets name to empty string
	 */
	public: FuelObserver();

	/**
	 * @brief Constructor that initialises name
	 * @param aName The name of the Observer
	 */
	public: FuelObserver(string aName);

	/**
	 * @brief Called by a subject object
	 * This will update the values of @p _lOXfuelState and @p _rP1fuelState
	 * and then call the @sa FuelObserver::assessFuel() for the remaining functionality
	 */
	public: void update();

	/**
	 * Sets the booster that will be observed
	 * @param[in] aBooster Pointer to the booster being observed
	 * @note method could be moved to parent class, in which case @p _concreteBooster could also be moved to parent Class
	 */
	public: void setSubjectBooster(Booster* aBooster);

	/**
	 * @brief Called in @p update()
	 * @details This code will analyse @p _lOXfuelState and @p _rP1fuelState , it will then print out
	 * a message accordingly.
	 */
	private: void assessFuel();

	/**
	 * @brief Returns a word describing the passed fuel level
	 * @param[in] level The fuel level to be described
	 * @details This function will assess the fuel level passed
	 * and return a word describing the level, such as: 'FULL', 'EMPTY', 'OK', 'LOW'...
	 */
	private: string fuelDescription(int level);

};

#endif
