/* 
 * File:   Star.h
 * Author: PC-Z510
 *
 * Created on 20 février 2015, 00:32
 */

#ifndef STAR_H
#define	STAR_H

#include "Object.h"


class Star : public Object {

public:
  Star();
  ~Star();
  int eventHandler(Event *p_e);
  void draw();
};

#endif	/* STAR_H */

