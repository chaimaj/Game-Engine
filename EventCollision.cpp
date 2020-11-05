/* 
 * File:   EventCollision.cpp
 * Author: PC-Z510
 * 
 * Created on 19 février 2015, 19:31
 */

#include "EventCollision.h"

EventCollision::EventCollision() {
    setType(DF_COLLISION_EVENT);
}

EventCollision::EventCollision(Object *p_o1, Object *p_o2, Position p) {
    setType(DF_COLLISION_EVENT);
    p_obj1=p_o1;
    p_obj2=p_o2;
    pos=p;
}

/// Set object that caused collision.

void EventCollision::setObject1(Object *p_new_o1) {
    p_obj1=p_new_o1;
}

/// Return object that caused collision.

Object *EventCollision::getObject1() const {
    return p_obj1;
}

/// Set object that was collided with.

void EventCollision::setObject2(Object *p_new_o2) {
    p_obj2=p_new_o2;
}

/// Return object that was collided with.

Object *EventCollision::getObject2() const {
    return p_obj2;
}

/// Set position of collision.

void EventCollision::setPosition(Position new_pos) {
    pos=new_pos;
}

/// Return position of collision.

Position EventCollision::getPosition() const {
    return pos;
}

