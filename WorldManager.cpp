/* 
 * File:   WorldManager.cpp
 * Author: PC-Z510
 * 
 * Created on 5 février 2015, 19:43
 */

#include "WorldManager.h"
#include "utility.h"
#include "EventCollision.h"
#include "GraphicsManager.h"
#include "EventOut.h"
#include "LogManager.h"
#include "Box.h"
#include "ViewObject.h"

WorldManager::WorldManager() {
}
bool WorldManager::instanceFlag = false;
WorldManager* WorldManager::single = NULL;

WorldManager *WorldManager::GetInstance() {
    {
        if (!instanceFlag) {
            single = new WorldManager();
            instanceFlag = true;
            return single;
        } else {
            return single;
        }
    }
}
/// Startup game world (initialize everything to empty).
/// Return 0.

int WorldManager::startUp() {
    updates.clear();
    deletions.clear();

}

/// Shutdown game world (delete all game world Objects).

void WorldManager::shutDown() {

    //delete all game objects
    ObjectList ol = updates; //copy list so can delete during iteration
    ObjectListIterator* li = new ObjectListIterator(&ol);
    for (li->first(); !li->isDone(); li->next()) {
        delete li->currentObject();
    }
    delete li;
    Manager::shutDown();

}

/// Add Object to world.
/// Return 0 if ok, else -1.

int WorldManager::insertObject(Object *p_o) {
    updates.insert(p_o);
}

/// Remove Object from world.
/// Return 0 if ok, else -1.

int WorldManager::removeObject(Object *p_o) {
    updates.remove(p_o);
}

/// Return list of all Objects in world.
/// If inactive is true, include inactive Objects.

ObjectList WorldManager::getAllObjects(bool inactive) const {
    return updates;
}

Box WorldManager::getBoundary() const {
    return boundary;
}

/// Set game world boundary.

void WorldManager::setBoundary(Box new_boundary) {
    boundary = new_boundary;
}

/// Get player view of game world.

Box WorldManager::getView() const {
    return view;
}

/// Set player view of game world.

void WorldManager::setView(Box new_view) {
    view = new_view;
}


/// Indicate Object is to be deleted at end of current game loop.
/// Return 0 if ok, else -1.

int WorldManager::markForDelete(Object *p_o) {

    //Object might already have been marked, so only add once
    ObjectList ol = deletions; //copy list so can delete during iteration
    ObjectListIterator* li = new ObjectListIterator(&ol);
    for (li->first(); !li->isDone(); li->next()) {
        if (li->currentObject() == p_o) { //Object already in list
            return 0;
        }
    }
    delete li;
    deletions.insert(p_o);

}

/// Update world.
/// Update positions of Objects based on their velocities.
/// Lastly, delete Objects marked for deletion.

void WorldManager::update() {

    //Delete all marked objects
    ObjectList ol = deletions; //copy list so can delete during iteration
    ObjectListIterator* li = new ObjectListIterator(&ol);
    for (li->first(); !li->isDone(); li->next()) {
        delete li->currentObject();
    }
    delete li;
    //clear list for next update
    deletions.clear();

    //all object in the world
    ObjectList obj = updates; //copy list so can delete during iteration
    ObjectListIterator* li2 = new ObjectListIterator(&obj);
    for (li2->first(); !li2->isDone(); li2->next()) {
        int x = li2->currentObject()->getXVelocityStep();
        int y = li2->currentObject()->getYVelocityStep();
        if ((x != 0) || (y != 0)) {
            Position old_pos = li2->currentObject()->getPosition();
            Position new_pos(old_pos.getX() + x, old_pos.getY() + y);
            moveObject(li2->currentObject(), new_pos);
        }
    }
    delete li2;
}

void WorldManager::draw() {
    utility u;
    ObjectList ol = updates; //copy list of current object
    ObjectListIterator* li = new ObjectListIterator(&ol);
    for (int i = 0; i <= DF_MAX_ALTITUDE; i++) {
        for (li->first(); !li->isDone(); li->next()) {
            if (li->currentObject()->getAltitude() == i) {
                Box temp_box = li->currentObject()->getBox();
                if ((u.boxIntersectsBox(temp_box, getView())) || (dynamic_cast <ViewObject *> (li->currentObject())))
                    li->currentObject()->draw();
            }
        }
    }
    delete li;

}

ObjectList WorldManager::isCollision(Object* p_o, Position where) const {
    LogManager *l = LogManager::GetInstance();
    //make empty list
    ObjectList collision_list;

    utility u;

    Box b = u.getWorldBox(p_o, where);
    
    //iterate through all objects
    ObjectListIterator* li = new ObjectListIterator(&updates);

    for (li->first(); !li->isDone(); li->next()) {
        Object *p_temp_o = li->currentObject();
        if (p_temp_o != p_o) { // do not consider self

            Box b_temp = u.getWorldBox(p_temp_o);
            //same location and both solid?

            if ((u.boxIntersectsBox(b, b_temp)) && (p_temp_o->isSolid())) {
             
                collision_list.insert(p_temp_o);

            }
        }
    }
    delete li;
    return collision_list;

}

int WorldManager::moveObject(Object* p_o, Position where) {
    LogManager *l = LogManager::GetInstance();

    if (p_o ->isSolid()) { //need to be solid for collision

        //get collisions
        ObjectList list = isCollision(p_o, where);
        if (!list.isEmpty()) {

            bool do_move = true; //assume can move

            //iterate over list
            ObjectListIterator* li = new ObjectListIterator(&list);
            for (li->first(); !li->isDone(); li->next()) {

                Object *p_temp_o = li->currentObject();

                //create collision event
                EventCollision c(p_o, p_temp_o, where);

                //send to both objects
                p_o->eventHandler(&c);
                p_temp_o->eventHandler(&c);


                //if both HARD, then cannot move
                if ((p_o->getSolidness() == HARD)&&(p_temp_o->getSolidness() == HARD)) {

                    do_move = false; //can't move
                }
            }
            delete li;
            if (!do_move) {
                return -1;
            }

        }

    }
    // if here no collision is allow move

    p_o->setPosition(where);
    GraphicsManager * gr = GraphicsManager::GetInstance();
    if ((p_o->getPosition().getX() < 0) || (p_o->getPosition().getY() < 0) ||
            (p_o->getPosition().getX() > gr->getHorizontal()) || (p_o->getPosition().getY() > gr->getVertical())) {
        EventOut ov;
        p_o->eventHandler(&ov);
    }
    
    //if view is following this object, adjust view
    if (p_view_following==p_o){
        setViewPosition(p_o->getPosition());
    }

    return 0; // move was ok
}

/// Set view to center screen on Object.
/// Set to NULL to stop following.
/// If Object not legit, return -1 else return 0.

int WorldManager::setViewFollowing(Object *p_new_view_following) {

    //Set to NULL to turn 'off' following
    if (p_new_view_following == NULL) {
        p_view_following = NULL;
        return 0;
    }
    bool found = false;
    //Iterate over all object
    ObjectList ol = updates; //copy list of current object
    ObjectListIterator* li = new ObjectListIterator(&ol);
    for (li->first(); !li->isDone(); li->next()) {
        
        if (li->currentObject()==p_new_view_following){
            found=true;
        }
    }
    delete li;
    
    //if found, adjust attribute accordingly and set view positions
    if (found){
        p_view_following = p_new_view_following;
        setViewPosition(p_view_following->getPosition());
        return 0;
    }
    
    // if we get here, was not legit, don't change current view
    return -1;

}

/// Set view to center screen on Position view_pos.
/// View edge will not go beyond world boundary.

void WorldManager::setViewPosition(Position view_pos) {

    //Make sure horizontal not out of world boundary
    int x = view_pos.getX() - view.getHorizontal() / 2;

    if ((x + view.getHorizontal()) > boundary.getHorizontal()) {
        x = boundary.getHorizontal() - view.getHorizontal();
    }

    //Make sure vertical not out of world boundary
    int y = view_pos.getY() - view.getVertical() / 2;
    if ((y + view.getVertical()) > boundary.getVertical()) {
        y = boundary.getVertical() - view.getVertical();
    }
    if (y < 0) {
        y = 0;
    }

    //Set view
    Position new_corner(x, y);
    view.setCorner(new_corner);

}

bool WorldManager::isValid(string event_type) const{
    return true;
}