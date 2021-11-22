#include <exception>
#include <string>
using namespace std;

#ifndef __Observer_h__
#define __Observer_h__

/**
 * @brief A Booster observer class
 * @author Jonathan Enslin - u19103345
 */
class Observer
{
	/// Name of the observer
	protected: string _observerName;

	/**
	 * @brief Sets the name of the observer
	 * @param[in] name Name to be assigned
	 */
	public: void setName(string name);

	public: virtual void update() = 0;
};

#endif
