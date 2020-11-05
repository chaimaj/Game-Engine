/* 
 * File:   EventStep.cpp
 * Author: PC-Z510
 * 
 * Created on 9 février 2015, 21:35
 */

#include "EventStep.h"

EventStep::EventStep() {
    setType(DF_STEP_EVENT);
    step_count=0;
}

EventStep::EventStep(int init_step_count){
    setType(DF_STEP_EVENT);
    step_count=init_step_count;
}
  
  /// Set step count.
void EventStep::setStepCount(int new_step_count){
    step_count= new_step_count;
}

  /// Get step count.
  int EventStep::getStepCount() const{
      return step_count;
  }
  
 


