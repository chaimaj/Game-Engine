/* 
 * File:   game.cpp
 * Author: PC-Z510
 *
 * Created on 5 février 2015, 21:06
 */

#include <cstdlib>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <stdlib.h>
#include <sstream>
#include <iostream>

#include "LogManager.h"
#include "Clock.h"
#include "GameManager.h"
#include "Position.h"
#include "Object.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"
#include "WorldManager.h"
#include "GraphicsManager.h"
#include "ObjectTest.h"
#include "ObjectCollider.h"
#include "Star.h"
#include "Frame.h"
#include "Sprite.h"
#include "ResourceManager.h"
#include "ViewObject.h"

using namespace std;



#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

int main(int argc, char** argv) {
    GameManager *g;
    g = GameManager::GetInstance();
    g->startUp();
    LogManager *l;
    l = LogManager::GetInstance();
    l->setFlush(true);

    WorldManager *w;
    w = WorldManager::GetInstance();
    ResourceManager *rm = ResourceManager::GetInstance();
    rm->startUp();
    rm->loadSprite("ship-spr.txt", "label");
    rm->loadSprite("explosion-spr.txt", "label2");
    Sprite *spr = rm->getSprite("label");
    Sprite *spr2 = rm->getSprite("label2");

    ObjectTest *Hero = new ObjectTest(); // Object to move with arrows
    Hero->setSprite(spr2,true);
    
    ViewObject *view = new ViewObject();
    view ->setViewString("Points");
    view->setValue(0);
    view->setLocation(TOP_RIGHT);
    view ->setColor(COLOR_YELLOW);
    //new ObjectCollider(); // moving collider, solidness hard and restarting when going out of the screen

    Star *obj = new Star();
    obj->setSprite(spr, true);


    g->run(33);

    rm->shutDown();
    g->shutDown();
    return 0;


}


