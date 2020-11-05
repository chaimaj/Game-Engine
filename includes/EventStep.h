/* 
 * File:   EventStep.h
 * Author: PC-Z510
 *
 * Created on 9 février 2015, 21:35
 */

#ifndef EVENTSTEP_H
#define	EVENTSTEP_H

#include "Event.h"

#define DF_STEP_EVENT "__step__"

class EventStep : public Event {

 private:
  int step_count;  /// Iteration number of game loop.
  
  
 public:
  /// Default constructor.
  EventStep();
  
  /// Constructor with initial step count.
  EventStep(int init_step_count);
  
  /// Set step count.
  void setStepCount(int new_step_count);

  /// Get step count.
  int getStepCount() const;
  
 
};

#endif	/* EVENTSTEP_H */

