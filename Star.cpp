/* 
 * File:   Star.cpp
 * Author: PC-Z510
 * 
 * Created on 20 février 2015, 00:32
 */

#include "Star.h"

#include <stdlib.h>  // for random()

#include "LogManager.h"
#include "WorldManager.h"
#include "EventStep.h"
#include "GraphicsManager.h"
#include "EventKeyboard.h"
#include "EventOut.h"

Star::Star() : Object() {


    // Set object type.
    setType("Star");

    setAltitude(0); // Make them in the background.

    //set solidness
    setSolidness(HARD);

    GraphicsManager *graphics_manager = GraphicsManager::GetInstance();
    Position pos(random() % graphics_manager->getHorizontal(),
            random() % graphics_manager->getVertical());
    setPosition(pos);
    
    Object::registerInterest(DF_STEP_EVENT);



}

Star::~Star() {

}


// Handle event.
// Return 0 if ignored, else 1.

int Star::eventHandler(Event *p_e) {
    WorldManager *w = WorldManager::GetInstance();
    GraphicsManager *gr = GraphicsManager::GetInstance();
    if (p_e->getType() == DF_STEP_EVENT) {
        Position p(this->getPosition().getX() - 1, this->getPosition().getY());
        w->moveObject(this, p);
        return 1;
    }
    if (p_e->getType() == DF_OUT_EVENT) {
        Position p(gr->getHorizontal() + 1, random() % (gr->getVertical() - 4) + 4);
        setPosition(p);
        return 1;
    }

    // If get here, have ignored this event.
    return 0;
}

// If moved off left edge, move back to far right.

void Star::draw() {
    // GraphicsManager *gr = GraphicsManager::GetInstance();
    //gr->drawCh(this->getPosition(), '.', 7);
    Object::draw();

}
