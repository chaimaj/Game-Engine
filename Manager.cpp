/* 
 * File:   Manager.cpp
 * Author: PC-Z510
 * 
 * Created on 5 février 2015, 18:28
 */
#include <cstdlib>

using namespace std;
#include "Manager.h"
#include "WorldManager.h"
#include "ObjectListIterator.h"
#include "LogManager.h"

Manager::Manager() {
    event_count = 0;
}

Manager::~Manager() {
}

int Manager::startUp() {

}

void Manager::shutDown() {

}

void Manager::setisStarted(bool b) {
    is_started = b;
}

//int Manager::onEvent(Event* p_event) const {
//    int count = 0;
//    WorldManager *w = WorldManager::GetInstance();
//    ObjectList ol = w->getAllObjects();
//    ObjectListIterator* li = new ObjectListIterator(&ol); //create an iterator
//    for (li->first(); !li->isDone(); li->next()) { // looping the iterator
//        li->currentObject()->eventHandler(p_event);
//        count++;
//    }
//    delete li;
//    return count;
//}

bool Manager::isStarted() const {
    return is_started;
}

/// Indicate interest in event.
/// Return 0 if ok, else -1.
/// (Note, doesn't check to see if Object is already registered.)

int Manager::registerInterest(Object *p_o, string event_type) {
    LogManager *log = LogManager::GetInstance();
    if (!isValid(event_type)){
        log->writeLog(" is not valid");
        return -1;
    }
    
    //Check if previously added this event
    for (int i = 0; i < event_count; i++) {
        if (event_name[i] == event_type) {
            obj_list[i].insert(p_o);
        }
    }

    //Otherwise, this is a new event
    if (event_count >= DF_MAX_EVENTS) {
        return -1; // list is full
    }

    event_name[event_count] = event_type;
    obj_list[event_count].clear();
    obj_list[event_count].insert(p_o);
    event_count++;
    return 0;

}

/// Indicate no more interest in event. 
/// Return 0 if ok, else -1.

int Manager::unregisterInterest(Object *p_o, string event_type) {

    //check for event
    int pos;
    for (int i = 0; i < event_count; i++) {
        if (event_name[i] == event_type) {
            obj_list[i].remove(p_o);
            pos = i;
        }
    }

    //if list now empty
    if (obj_list[pos].isEmpty()) {
        for (int j = pos; j < event_count - 1; j++) {
            obj_list[j] = obj_list[j + 1];
            event_name [j] = event_name[j + 1];
        }
        event_count--;
    }

}

/// Send event to all interested Objects.
/// Return count of number of events sent.

int Manager::onEvent(Event *p_event) const {
    LogManager *log = LogManager::GetInstance();
    int count = 0;
    for (int i = 0; i < event_count; i++) {
        if (event_name[i] == p_event->getType()) {
            ObjectListIterator* li = new ObjectListIterator(&obj_list[i]); //create an iterator
            for (li->first(); !li->isDone(); li->next()) { // looping the iterator
                li->currentObject()->eventHandler(p_event);
                count++;
            }
            delete li;

        }
    }
    return count;
}

bool Manager::isValid(string event_type) const{
    
}






