/* 
 * File:   Event.cpp
 * Author: PC-Z510
 * 
 * Created on 9 février 2015, 21:34
 */

#include "Event.h"

Event::Event() {
}

Event::~Event() {
}

void Event::setType(string new_type){
     event_type=new_type;
 }  

  /// Get event type.
string Event::getType() const{
      return event_type;
  }

