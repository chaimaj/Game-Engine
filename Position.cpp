/* 
 * File:   Position.cpp
 * Author: PC-Z510
 * 
 * Created on 9 février 2015, 15:23
 */

#include "Position.h"

Position::Position() {
    x=0;
    y=0;
}

Position::Position(int init_x,int init_y) {
    x=init_x;
    y=init_y;
    
}

void Position::setX(int new_x){
    x=new_x;
}
int Position::getX() const{
    return x;
}

void Position::setY(int new_y){
    y=new_y;
}
int Position::getY() const{
    return y;
}

void Position::setXY(int new_x, int new_y){
    x=new_x;
    y=new_y;
}