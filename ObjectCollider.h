/* 
 * File:   ObjectCollider.h
 * Author: PC-Z510
 *
 * Created on 19 février 2015, 22:42
 */

#ifndef OBJECTCOLLIDER_H
#define	OBJECTCOLLIDER_H

#include "Object.h"


class ObjectCollider : public Object {

 private:
  void moveToStart();
  void out();
 

 public:
  ObjectCollider();
  ~ObjectCollider();
  int eventHandler(Event *p_e);
  void draw();
};

#endif	/* OBJECTCOLLIDER_H */

