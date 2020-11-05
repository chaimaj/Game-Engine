/* 
 * File:   Box.cpp
 * Author: PC-Z510
 * 
 * Created on 7 mars 2015, 18:55
 */

#include "Box.h"

/// Create box with (0,0) for corner, and 0 for horiz and vert.
Box::Box() {
    corner = Position(0,0);
    horizontal=0;
    vertical=0;
}

/// Create box with upper-left corner, horiz and vert sizes.
  Box::Box(Position init_corner, int init_horizontal, int init_vertical){
      corner = Position(init_corner.getX(),init_corner.getY());
      horizontal=init_horizontal;
      vertical= init_vertical;
  }

  
/// Set upper left corner of box.
  void Box::setCorner(Position new_corner){
      corner = Position(new_corner.getX(),new_corner.getY());
  }

  /// Get upper left corner of box.
  Position Box::getCorner() const{
      return corner;
  }

  /// Set horizontal size of box.
  void Box::setHorizontal(int new_horizontal){
      horizontal =new_horizontal;
  }

  /// Get horizontal size of box.
  int Box::getHorizontal() const{
   return horizontal;   
  }

  /// Set vertical size of box.
  void Box::setVertical(int new_vertical){
      vertical = new_vertical;
  }

  /// Get vertical size of box.
  int Box::getVertical() const{
      return vertical; 
  }

 