/* 
 * File:   ObjectTest.h
 * Author: PC-Z510
 *
 * Created on 17 février 2015, 20:54
 */

#ifndef OBJECTTEST_H
#define	OBJECTTEST_H

#include "Object.h"


class ObjectTest : public Object {

 private:
  void moveToStart();
  void out();
 

 public:
  ObjectTest();
  ~ObjectTest();
  int eventHandler(Event *p_e);
  void draw();
};

#endif	/* OBJECTTEST_H */

