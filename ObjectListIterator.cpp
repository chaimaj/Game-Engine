/* 
 * File:   ObjectListIterator.cpp
 * Author: PC-Z510
 * 
 * Created on 9 février 2015, 16:51
 */

#include "ObjectListIterator.h"
#include "ObjectList.h"


/// Create iterator, over indicated list.
ObjectListIterator::ObjectListIterator(const ObjectList *p_l){
    p_listi=p_l;
    first();
}

  /// Set iterator to first item in list.
 void ObjectListIterator::first(){
    index=0;  
 }

  /// Set iterator to next item in list.
  void ObjectListIterator::next(){
      if (index < p_listi->getCount()){
          index ++;
      }
  }

  /// Return true if at end of list.
  bool ObjectListIterator::isDone() const{
      return (index ==p_listi->getCount());
  }

  /// Return pointer to current item in list, NULL if done/empty.
  Object *ObjectListIterator::currentObject() const{
      return p_listi->list[index];
  }     


