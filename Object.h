/* 
 * File:   Object.h
 * Author: PC-Z510
 *
 * Created on 9 février 2015, 15:28
 */
#ifndef OBJECT_H
#define	OBJECT_H

#include "Position.h"
#include "Event.h"
#include "Sprite.h"
#include "Box.h"

#include <string>

#define DF_MAX_OBJ_EVENTS 100

using namespace std;


/// Types of solidness of Object.

enum Solidness {
    HARD, ///< Object causes collisions and impedes.
    SOFT, ///< Object causes collision, but doesn't impede.
    SPECTRAL ///< Object doesn't cause collisions.
};

class Object {
private:
    int id; ///< Unique Object identifier.
    Position pos; ///< Position in the game world.
    string type; ///< User-defined identification.
    int altitude; ///< 0 to MAX supported (lower drawn first)
    float x_velocity; ///< Horizontal speed in spaces per game step.
    float x_velocity_countdown; ///< Countdown to horizontal movement.
    float y_velocity; ///< Vertical speed in spaces per game step.
    float y_velocity_countdown; ///< Countdown to vertical movement.
    Solidness solidness; ///< Solidness state of Object.
    Sprite *p_sprite; ///< Sprite associated with Object.
    bool sprite_center; ///< True if sprite centered on Object.
    char sprite_transparency; ///< Sprite transparent character (0 if none).
    int sprite_index; ///< Current index frame for sprite.
    int sprite_slowdown; ///< Slowdown rate (1 = no slowdown, 0 = stop).
    int sprite_slowdown_count;
    Box box; //Box for sprite boundary and collision
    int event_count;
    string event_name [DF_MAX_OBJ_EVENTS];

public:
    /// Construct Object. Set default parameters and
    /// add to game world (WorldManager).
    Object();

    /// Destroy Object. Unregister for any interested events.
    /// Remove from game world (WorldManager).
    virtual ~Object();

    /// Set Object id.
    void setId(int new_id);

    /// Get Object id.
    int getId() const;

    /// Set type identifier of Object.
    void setType(string new_type);

    /// Get type identifier of Object.
    string getType() const;

    /// Set Object Sprite to new one.
    /// If set_box is true, set bounding box to size of Sprite.
    /// Set sprite index to 0 (first frame).
    void setSprite(Sprite *p_new_sprite, bool set_box = true);

    /// Return pointer to Sprite associated with this Object.
    Sprite *getSprite() const;

    /// Set Sprite to be centered at Object position (pos).
    void setCentered(bool centered = true);

    /// Indicates if Sprite is centered at Object position (pos).
    bool isCentered() const;
    /// Set index of current Sprite frame to be displayed.
    void setSpriteIndex(int new_sprite_index);

    /// Return index of current Sprite frame to be displayed.
    int getSpriteIndex() const;

    /// Slows down sprite animations.
    /// Slowdown value in multiples of WorldManager frame time.
    void setSpriteSlowdown(int new_sprite_slowdown);
    int getSpriteSlowdown() const;
    void setSpriteSlowdownCount(int new_sprite_slowdown_count);
    int getSpriteSlowdownCount() const;

    ///< Return True if Object is HARD or SOFT, else false.
    bool isSolid() const;

    /// Set solidness of Object, with checks for consistency.  
    /// Return 0 if ok, else -1.
    int setSolidness(Solidness new_solid);

    /// Return solidness of Object.
    Solidness getSolidness() const;

    /// Set Position of Object.
    void setPosition(Position new_pos);

    /// Get Position of Object.
    Position getPosition() const;

    //Set object altitude
    //check for in range [0,DF_MAX_ALTITUDE]
    //Return 0 if ok, else -1
    int setAltitude(int new_altitude);

    //return object altitude
    int getAltitude() const;

    /// Set x velocity of Object.
    void setXVelocity(float new_x_velocity);

    /// Get x velocity of Object.
    float getXVelocity() const;

    /// Set y velocity of Object.
    void setYVelocity(float new_y_velocity);

    /// Get y velocity of Object.
    float getYVelocity() const;

    /// Perform 1 step of velocity in horizontal direction.
    /// Return horizontal distance moved this step.
    int getXVelocityStep();

    /// Perform 1 step of velocity in vertical direction.
    /// Return vertical distance moved this step.
    int getYVelocityStep();

    //Set Object's bounding box
    void setBox(Box new_box);

    //Get object's bounding box
    Box getBox() const;

    /// Handle event (default is to ignore everything).
    /// Return 0 if ignored, else 1.
    virtual int eventHandler(Event *p_event);

    /// Register for interest in event.  
    /// Keeps track of manager and event.  
    /// Return 0 if ok, else -1.
    int registerInterest(string event_type);

    /// Unregister for interest in event.  
    /// Return 0 if ok, else -1.
    int unregisterInterest(string event_type);

    virtual void draw();


};

#endif	/* OBJECT_H */

