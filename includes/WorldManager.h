/* 
 * File:   WorldManager.h
 * Author: PC-Z510
 *
 * Created on 5 février 2015, 19:43
 */

#ifndef WORLDMANAGER_H
#define	WORLDMANAGER_H

#define DF_MAX_ALTITUDE 4

#include "Manager.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"

class WorldManager : public Manager {
private:
    //Singleton
    WorldManager();
    WorldManager(WorldManager const &copy);
    void operator=(WorldManager const&);
    static bool instanceFlag;
    static WorldManager *single;

    ObjectList updates; //all objects in world to update
    ObjectList deletions; //all objects in world to delete
    Box boundary; //World boundary
    Box view; //Player view of game world
    Object *p_view_following;


public:
    // get the one and only instance
    static WorldManager *GetInstance();

    /// Startup game world (initialize everything to empty).
    /// Return 0.
    int startUp();

    /// Shutdown game world (delete all game world Objects).
    void shutDown();

    /// Add Object to world.
    /// Return 0 if ok, else -1.
    int insertObject(Object *p_o);

    /// Remove Object from world.
    /// Return 0 if ok, else -1.
    int removeObject(Object *p_o);

    /// Return list of all Objects in world.
    /// If inactive is true, include inactive Objects.
    ObjectList getAllObjects(bool inactive = false) const;

    /// Indicate Object is to be deleted at end of current game loop.
    /// Return 0 if ok, else -1.
    int markForDelete(Object *p_o);

    /// Update world.
    /// Update positions of Objects based on their velocities.
    /// Lastly, delete Objects marked for deletion.
    void update();

    /// Get game world boundary.
    Box getBoundary() const;

    /// Set game world boundary.
    void setBoundary(Box new_boundary);

    /// Get player view of game world.
    Box getView() const;

    /// Set player view of game world.
    void setView(Box new_view);

    //draw all objects
    void draw();

    /// Return list of Objects collided with at Position 'where'.
    /// Collisions only with solid Objects.
    /// Does not consider if p_o is solid or not.
    ObjectList isCollision(Object *p_o, Position where) const;

    /// Move Object. 
    /// If no collision with solid, move ok else don't move Object.
    /// If Object is Spectral, move ok.
    /// If move ok, adjust screen if following this Object.
    /// Return 0 if move ok, else -1 if collision with solid.
    int moveObject(Object *p_o, Position where);

    /// Set view to center screen on Object.
    /// Set to NULL to stop following.
    /// If Object not legit, return -1 else return 0.
    int setViewFollowing(Object *p_new_view_following);

    /// Set view to center screen on Position view_pos.
    /// View edge will not go beyond world boundary.
    void setViewPosition(Position view_pos);
    
    bool isValid(string event_type) const;

};

#endif	/* WORLDMANAGER_H */

