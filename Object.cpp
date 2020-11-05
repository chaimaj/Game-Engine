/* 
 * File:   Object.cpp
 * Author: PC-Z510
 * 
 * Created on 9 février 2015, 15:28
 */

#include "Object.h"
#include "Position.h"
#include "WorldManager.h"
#include "Event.h"
#include "LogManager.h"
#include "GraphicsManager.h"
#include "Sprite.h"
#include "Box.h"
#include "GameManager.h"
#include "EventKeyboard.h"
#include "EventMouse.h"
#include "InputManager.h"
#include "EventStep.h"

#include <math.h> 

Object::Object() {
    id = 0;
    pos = Position();
    type = "";
    altitude = DF_MAX_ALTITUDE / 2;
    WorldManager *w;
    w = WorldManager::GetInstance();
    w->insertObject(this);
    event_count=0;
    box = Box();
}

Object::~Object() {
    WorldManager *w;
    w = WorldManager::GetInstance();
    w->removeObject(this);
    for (int i = event_count-1; i>=0; i--){
        this->unregisterInterest(event_name[i]);
    }
}

int Object::getId() const {
    return id;
}

void Object::setId(int new_id) {
    id = new_id;
}

Position Object::getPosition() const {
    return pos;
}

void Object::setPosition(Position new_pos) {
    pos.setXY(new_pos.getX(), new_pos.getY());
}

string Object::getType() const {
    return type;
}

void Object::setType(string new_type) {
    type = new_type;
}

int Object::setAltitude(int new_altitude) {
    if ((new_altitude >= 0)&& (new_altitude <= DF_MAX_ALTITUDE)) {
        altitude = new_altitude;
        return 0;
    }
    return -1;
}

/// Set Object Sprite to new one.
/// If set_box is true, set bounding box to size of Sprite.
/// Set sprite index to 0 (first frame).

void Object::setSprite(Sprite *p_new_sprite, bool set_box) {
    LogManager *l = LogManager::GetInstance();
    p_sprite = p_new_sprite;
    sprite_index = 0;
    sprite_slowdown = 1;
    sprite_slowdown_count = 0;
    if (set_box) {
        l->writeLog(" set horizontal %d", p_new_sprite->getWidth());
        box.setHorizontal(p_new_sprite->getWidth());
        l->writeLog(" set vertical %d", p_new_sprite->getHeight());
        box.setVertical(p_new_sprite->getHeight());

    } else {
        box.setHorizontal(1);
        box.setVertical(1);
    }
}

/// Return pointer to Sprite associated with this Object.

Sprite *Object::getSprite() const {
    return p_sprite;
}

/// Set Sprite to be centered at Object position (pos).

void Object::setCentered(bool centered) {
    sprite_center = centered;
}

/// Indicates if Sprite is centered at Object position (pos).

bool Object::isCentered() const {
    return sprite_center;
}

/// Set index of current Sprite frame to be displayed.

void Object::setSpriteIndex(int new_sprite_index) {
    sprite_index = new_sprite_index;
}

/// Return index of current Sprite frame to be displayed.

int Object::getSpriteIndex() const {
    return sprite_index;
}

/// Slows down sprite animations.
/// Slowdown value in multiples of WorldManager frame time.

void Object::setSpriteSlowdown(int new_sprite_slowdown) {
    sprite_slowdown = new_sprite_slowdown;
}

int Object::getSpriteSlowdown() const {
    return sprite_slowdown;
}

void Object::setSpriteSlowdownCount(int new_sprite_slowdown_count) {
    sprite_slowdown_count = new_sprite_slowdown_count;
}

int Object::getSpriteSlowdownCount() const {
    return sprite_slowdown_count;
}

int Object::getAltitude() const {
    return altitude;
}

int Object::eventHandler(Event *p_event) {
    LogManager *l;
    l = LogManager::GetInstance();
    if (p_event->getType() == "__step__") {
        return 1;
    }
    return 0;
}

/// Set x velocity of Object.

void Object::setXVelocity(float new_x_velocity) {
    x_velocity = new_x_velocity;
    x_velocity_countdown = 1;
}

/// Get x velocity of Object.

float Object::getXVelocity() const {
    return x_velocity;
}

/// Set y velocity of Object.

void Object::setYVelocity(float new_y_velocity) {
    y_velocity = new_y_velocity;
    y_velocity_countdown = 1;
}

/// Get y velocity of Object.

float Object::getYVelocity() const {
    return y_velocity;
}

/// Perform 1 step of velocity in horizontal direction.
/// Return horizontal distance moved this step.

int Object::getXVelocityStep() {
    if (x_velocity == 0) {
        return 0; // no velocity so no more
    }
    //see if moving this step
    x_velocity_countdown -= fabs(x_velocity);
    if (x_velocity_countdown > 0) {
        return 0; //not time to move
    }
    //moving this step, so figure out how far
    int spaces = floor(1 - x_velocity_countdown);
    x_velocity_countdown = 1 + fmod(x_velocity_countdown, 1);

    //return number of spaces to move
    if (x_velocity > 0) {
        return spaces;
    } else return -1 * spaces;
}

/// Perform 1 step of velocity in vertical direction.
/// Return vertical distance moved this step.

int Object::getYVelocityStep() {
    if (y_velocity == 0) {
        return 0; // no velocity so no more
    }
    //see if moving this step
    y_velocity_countdown -= fabs(y_velocity);
    if (y_velocity_countdown > 0) {
        return 0; //not time to move
    }
    //moving this step, so figure out how far
    int spaces = floor(1 - y_velocity_countdown);
    y_velocity_countdown = 1 + fmod(y_velocity_countdown, 1);

    //return number of spaces to move
    if (y_velocity > 0) {
        return spaces;
    } else return -1 * spaces;

}

///< Return True if Object is HARD or SOFT, else false.

bool Object::isSolid() const {
    if ((solidness == HARD) || (solidness == SOFT)) {
        return true;
    }
    return false;
}

/// Set solidness of Object, with checks for consistency.  
/// Return 0 if ok, else -1.

int Object::setSolidness(Solidness new_solid) {
    solidness = new_solid;
}

/// Return solidness of Object.

Solidness Object::getSolidness() const {
    return solidness;
}

//Set Object's bounding box

void Object::setBox(Box new_box) {
    box = new_box;
}

//Get object's bounding box

Box Object::getBox() const {
    return box;
}

int Object::registerInterest(string event_type){
    LogManager *log = LogManager::GetInstance();
    //check if room
    if (event_count == DF_MAX_OBJ_EVENTS){
        return -1;
    }
    
    //Register with appropriate manager
    if (event_type ==DF_STEP_EVENT){
        log->writeLog("event step");
        GameManager::GetInstance()->registerInterest(this,event_type);
    }
    else if ((event_type == DF_KEYBOARD_EVENT) || (event_type == DF_MOUSE_EVENT)){
        log->writeLog("event keyboard");
        InputManager::GetInstance()->registerInterest(this,event_type);
    }
    else {
        log->writeLog("event other");
        WorldManager::GetInstance()->registerInterest(this,event_type);
    }
    
    //keep track of added event
    event_name[event_count] = event_type;
    event_count++;
    
    //all is well
    return 0;
}

int Object::unregisterInterest(string event_type){
    
    //Check if previously registered
    bool found = false;
    int pos=0;
    for (int i=0; i<event_count -1; i++){
        if (event_name[i]==event_type){
            found =true;
            pos=i;
        }
    }
    
    if (!found){
        return -1;
    }
    
    //unregister with appropriate manager
    if (event_type == DF_STEP_EVENT){
        GameManager::GetInstance()->unregisterInterest(this,event_type);
    }
    else if ((event_type == DF_KEYBOARD_EVENT) || (event_type == DF_MOUSE_EVENT)){
        InputManager::GetInstance()->unregisterInterest(this,event_type);
    }
    else {
        WorldManager::GetInstance()->unregisterInterest(this,event_type);
    }
    
    //keep track
    for (int j=pos; j<event_count-1; j++){
        event_name[j] = event_name [j+1];
    }
    event_count--;
    
    //all is ok
    return 0;
    
}

void Object::draw() {
    
    //if sprite not defined don't continue further
    if (p_sprite == NULL) {
        return;
    }

    int index = getSpriteIndex();
    //ask graphics manager to draw current frame
    GraphicsManager::GetInstance()->drawFrame(pos, p_sprite->getFrame(index), sprite_center, p_sprite->getColor());
    //if slowdown is 0, then animation is frozen
    if (getSpriteSlowdown() == 0) {
        return;
    }

    //increment counter
    int count = getSpriteSlowdownCount();
    count++;

    //Advance sprite index, if appropriate
    if (count >= getSpriteSlowdown()) {
        count = 0; //reset counter
        index++; //advance frame

        //if at last frame, loop to beginning
        if (index >= p_sprite->getFrameCount()) {
            index = 0;
        }
    }

    setSpriteSlowdownCount(count);

    //set index for next draw
    setSpriteIndex(index);
}