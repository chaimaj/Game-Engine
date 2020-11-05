/* 
 * File:   ObjectCollider.cpp
 * Author: PC-Z510
 * 
 * Created on 19 février 2015, 22:42
 */
#include <stdlib.h>  // for random()



#include "LogManager.h"
#include "WorldManager.h"
#include "EventStep.h"
#include "GraphicsManager.h"
#include "EventKeyboard.h"
#include "ObjectCollider.h"
#include "EventOut.h"

ObjectCollider::ObjectCollider() : Object() {

    GraphicsManager *graphics_manager = GraphicsManager::GetInstance();
    
    setPosition(Position(graphics_manager->getHorizontal(),random() % graphics_manager->getVertical()));
    // Set object type.
    setType("Collider");
    
    //set solidness
    setSolidness(HARD);

    //setXVelocity(-0.5); // 1 space left every 2 frames
    //setYVelocity(0.25);

    //moveToStart();

}

ObjectCollider::~ObjectCollider() {

}

// Handle event.
// Return 0 if ignored, else 1.

int ObjectCollider::eventHandler(Event *p_e) {
    WorldManager *w = WorldManager::GetInstance();
    GraphicsManager *gr=GraphicsManager::GetInstance();
    if (p_e->getType() == DF_STEP_EVENT) {
        Position p(this->getPosition().getX() - 1, this->getPosition().getY());
        w->moveObject(this,p);
        return 1;
    }
    if (p_e->getType() == DF_OUT_EVENT) {
        Position p(gr->getHorizontal()+1, random()%(gr->getVertical()-4) + 4);
        setPosition(p);
        return 1;
    }
    
    // If get here, have ignored this event.
    return 0;
}

// If moved off left edge, move back to far right.

void ObjectCollider::out() {



}

// Move Saucer to starting location on right side of screen.

void ObjectCollider::moveToStart() {


}

void ObjectCollider::draw() {
    GraphicsManager *gr = GraphicsManager::GetInstance();
    gr->drawCh(this->getPosition(), 'O', 4);

}
