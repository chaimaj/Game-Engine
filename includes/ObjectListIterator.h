/* 
 * File:   ObjectListIterator.h
 * Author: PC-Z510
 *
 * Created on 9 février 2015, 16:51
 */

#ifndef OBJECTLISTITERATOR_H
#define	OBJECTLISTITERATOR_H

#include "ObjectList.h"

class Object;
class ObjectList;

class ObjectListIterator {

 private:
  ObjectListIterator();	///< Iterator must be given list when created.
  int index;			///< Index into list.
  const ObjectList *p_listi;	///< List iterating over.

 public:
  /// Create iterator, over indicated list.
  ObjectListIterator(const ObjectList *p_list);

  /// Set iterator to first item in list.
  void first();

  /// Set iterator to next item in list.
  void next();

  /// Return true if at end of list.
  bool isDone() const;

  /// Return pointer to current item in list, NULL if done/empty.
  Object *currentObject() const;     
  
  
};

#endif	/* OBJECTLISTITERATOR_H */

