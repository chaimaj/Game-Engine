/* 
 * File:   EventMouse.cpp
 * Author: PC-Z510
 * 
 * Created on 18 février 2015, 13:35
 */

#include "EventMouse.h"

EventMouse::EventMouse() {
    setType(DF_MOUSE_EVENT);
}

/// Load mouse event's action.

void EventMouse::setMouseAction(enum MouseActionList new_mouse_action) {
    mouse_action=new_mouse_action;
}

/// Get mouse event's action.

enum MouseActionList EventMouse::getMouseAction() const {
    return mouse_action;
}

/// Set mouse event's x coordinate.

void EventMouse::setMouseX(int new_x) {
    mouse_x=new_x;
}

/// Get mouse event's x coordinate.

int EventMouse::getMouseX() const {
    return mouse_x;
}

/// Set mouse event's y coordinate.

void EventMouse::setMouseY(int new_y) {
    mouse_y=new_y;
}

/// Get mouse event's y coordinate.

int EventMouse::getMouseY() const {
    return mouse_y;
}