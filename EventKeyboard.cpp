///
/// A "keyboard" event
/// 

#include "EventKeyboard.h"

 
 EventKeyboard::EventKeyboard(){
     setType(DF_KEYBOARD_EVENT);
 }

  /// Set key in event.
  void EventKeyboard::setKey(int new_key){
      key_val=new_key;
  }

  /// Get key from event.
  int EventKeyboard::getKey() const{
      return key_val;
  }
