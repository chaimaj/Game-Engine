/* 
 * File:   Event.h
 * Author: PC-Z510
 *
 * Created on 9 février 2015, 21:34
 */

#ifndef EVENT_H
#define	EVENT_H

#include <string>

#define DF_UNDEFINED_EVENT "__undefined__"

using std::string;

class Event {

 private:
  string event_type;      ///< Holds event type.

 public:
  /// Create base event.
  Event();

  /// Destructor.
  virtual ~Event();

  /// Set event type.
  virtual void setType(string new_type);  

  /// Get event type.
  virtual string getType() const;
}; 

#endif // __EVENT_H__


