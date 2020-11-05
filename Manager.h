/*
 * Manager.h
 *
 *  Created on: 5 févr. 2015
 *      Author: PC-Z510
 */


#ifndef MANAGER_H_
#define MANAGER_H_

#include <cstdlib>
#include <string>
#include "Event.h"
#include "Object.h"
#include "ObjectList.h"


#define DF_MAX_EVENTS 100	      ///< Max number of different events.

using namespace std;

class Manager {
private:

    string type;
    bool is_started;
    int event_count; ///< Number of events.
    string event_name[DF_MAX_EVENTS]; ///< List of events.
    ObjectList obj_list[DF_MAX_EVENTS]; ///< Objects interested in event.

protected:
    // Set type identifier of MAnager
    void setType(string Type);

public:
    Manager();
    virtual ~Manager();

    //getType identifier of Manager
    string getType() const;

    //startup Manager
    //Return 0 if ok, else negative number
    virtual int startUp();

    //Shutdown Manager
    virtual void shutDown();

    /// Send event to all interested Objects.
    /// Return count of number of events sent.
    int onEvent(Event *p_event) const;

    // Return true when StartUp () was executed ok, else false
    bool isStarted() const;

    void setisStarted(bool b);

    /// Indicate interest in event.
    /// Return 0 if ok, else -1.
    /// (Note, doesn't check to see if Object is already registered.)
    int registerInterest(Object *p_o, string event_type);

    /// Indicate no more interest in event. 
    /// Return 0 if ok, else -1.
    int unregisterInterest(Object *p_o, string event_type);
    
     /// Check if event is handled by this Manager.
    /// If handled, return true else false.
    /// (Base Manager always returns false.)
    virtual bool isValid(string event_type) const;


};

#endif /* MANAGER_H_ */
