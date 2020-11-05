/* 
 * File:   ObjectTest.cpp
 * Author: PC-Z510
 * 
 * Created on 17 février 2015, 20:54
 */


#include <stdlib.h>  // for random()


#include "ObjectTest.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "EventStep.h"
#include "GraphicsManager.h"
#include "EventKeyboard.h"
#include "GameManager.h"
#include "EventView.h"

ObjectTest::ObjectTest() : Object() {

    setPosition(Position(0, 0));
    // Set object type.
    setType("Test");
    
    //set solidness
    setSolidness(HARD);
    
    LogManager *l =LogManager::GetInstance();
    
    l->writeLog("create object with solidness hard");
    
    Object::registerInterest(DF_KEYBOARD_EVENT);
    
    Object::registerInterest(DF_STEP_EVENT);


    //setXVelocity(0.5); // 1 space left every 4 frames
    //setYVelocity(0.25);

    //moveToStart();

}

ObjectTest::~ObjectTest() {

}

// Handle event.
// Return 0 if ignored, else 1.

int ObjectTest::eventHandler(Event *p_e) {
    WorldManager* w = WorldManager::GetInstance();
    GameManager* g = GameManager::GetInstance();
    LogManager* l = LogManager::GetInstance();
    if (p_e->getType() == DF_STEP_EVENT) {
        l->writeLog("yeey step");
        EventView ev ("Points",1,true);
        l->writeLog("create event view");
        w->onEvent(&ev);
        l->writeLog("world manager on event");
        return 1;
    }
    if (p_e->getType() == DF_KEYBOARD_EVENT) {

        EventKeyboard *p_keyboard_event = static_cast<EventKeyboard *> (p_e);
        //left arrow
        switch (p_keyboard_event->getKey()) {
            case KEY_UP:
            {
                Position p(this->getPosition().getX(), this->getPosition().getY() - 1);
                w->moveObject(this,p);
                break;
            }
            case KEY_LEFT:
            {
                Position p(this->getPosition().getX() - 1, this->getPosition().getY());
                w->moveObject(this,p);
                break;
            }
            case KEY_RIGHT:
            {
                Position p(this->getPosition().getX() + 1, this->getPosition().getY());
                w->moveObject(this,p);
                break;
            }
            case KEY_DOWN:
            {
                Position p(this->getPosition().getX(), this->getPosition().getY() + 1);
                w->moveObject(this,p);
                break;
            }
            case ' ':
            {
                g->setGameOver(true);
                break;
            }
        }
       
    }
    // If get here, have ignored this event.
    return 0;
}

// If moved off left edge, move back to far right.

void ObjectTest::out() {



}

// Move Saucer to starting location on right side of screen.

void ObjectTest::moveToStart() {


}

void ObjectTest::draw() {
    Object::draw();

}
