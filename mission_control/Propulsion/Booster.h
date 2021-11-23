#include <exception>
#include <vector>
using namespace std;

#ifndef __Booster_h__
#define __Booster_h__

#include "Propulsion.h"

/**
 * @brief Booster class, child of Propulsion
 * @author Jonathan Enslin - u19103345
 */
class Booster : public Propulsion {
    /// Children in the composite structure
   protected:
    vector<Propulsion *> _children;
    /// LOX Fuel level as a percentage
   protected:
    int _lOXfuelLevel;
    /// RP1 Fuel level as a percentage
   protected:
    int _rP1fuelLevel;

    /// booster ID as int
   private:
    int booster_id;

   public:
    /**
     * @details See child classes for more implementation
     * This method returns null
     * @param index The index of the child booster to obtain
     * @return Booster* 
     */
    virtual Booster* getChildBooster(int index);

    /**
	 * @brief adds a propulsion object to the composite structure
	 * @param[in] aP the propulsion object to add to the composite
	 * @details @p aP will be to the vector of propulsion objects
	 */
   public:
    void
    add(Propulsion *aP) override;

    /**
	 * @brief removes a propulsion object
	 * @param aP Propulsion object to be removed
	 * @details This will @p aP from the @p _children vector
	 */
   public:
    void remove(Propulsion *aP) override;

    /**
	 * @brief Getter for the LOXfuelLevel
	 * @return the LOX fuel level value
	 */
   public:
    int getLOXfuelLevel();

    /**
	 * @brief Sets the LOX fuel level
	 * @param[in] aLOXfuelLevel The value LOX fuel level should be set to
	 */
   public:
    void setLOXfuelLevel(int aLOXfuelLevel);

    /**
	 * @brief Getter for the RP1 fuel level
	 * @return RP1 fuel level
	 */
   public:
    int getRP1fuelLevel();

    /**
	 * @brief Setter for the RP1 fuel level
	 * 
	 */
   public:
    void setRP1fuelLevel(int aRP1fuelLevel);

    /**
	 * @brief Getter for the booster id
	 * @return booster id
	 */
   public:
    int getBoosterId();

    /**
	 * @brief Sets the booster id
	 * @param[in] id The value the booster id should be set to
	 */
   public:
    void setBoosterId(int id);

    /**
	 * @brief Getter for the booster name
	 * @return booster name as string
	 */
   public:
    virtual string getName();

    /// @todo find out what this is
   public:
    virtual void operation();

   public:
    /**
	 * @brief Returns a clone of the entire tree structure
	 * 
	 * @return Propulsion*
	 */
    Propulsion *clone();

	public:
		/**
		 * @brief Destructor for @p Booster , deletes all branches
		 * 
		 */
	~Booster() override;
};

#endif
