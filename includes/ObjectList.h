/* 
 * File:   ObjectList.h
 * Author: PC-Z510
 *
 * Created on 9 février 2015, 16:38
 */

#ifndef OBJECTLIST_H
#define	OBJECTLIST_H

//#define DF_MAX_LIST_INIT 1
#define DF_MAX_LIST 5000

#include "Object.h"
#include "ObjectListIterator.h"

class Object;
class ObjectListIterator;

class ObjectList {

 private:
  int count;                  ///< Count of objects in list.
  //int max_count;              ///< Maximum objects in list (variable).
  Object *list[DF_MAX_LIST];            ///< Array of pointers to objects.

 public:
  friend class ObjectListIterator;           ///< Iterators can access.
  ObjectList();
  
//  ~ObjectList();
//
//  /// Copy contructor (does deep copy).
//  ObjectList(const ObjectList &other);
//   
//  /// Assignment operator (does deep copy).
//  ObjectList &operator=(const ObjectList &rhs);
 
  /// Insert object pointer in list.
  /// Return 0 if ok, else -1.
  int insert(Object *p_o);

  /// Remove object pointer from list,
  /// Return 0 if found, else -1.
  int remove(Object *p_o);

  /// Clear list (setting count to 0).
  void clear();

  /// Return count of number of objects in list.
  int getCount() const;

  /// Return true if list is empty, else false.
  bool isEmpty() const;

  /// Return true if list is full, else false.
  bool isFull() const;

  
};


#endif	/* OBJECTLIST_H */

