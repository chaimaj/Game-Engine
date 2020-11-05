/* 
 * File:   GameManager.cpp
 * Author: PC-Z510
 * 
 * Created on 5 février 2015, 19:43
 */

#include <time.h>
#include<iostream>

#include "GameManager.h"
#include "LogManager.h"
#include "Clock.h"
#include "WorldManager.h"
#include "Event.h"
#include "EventStep.h"
#include "Object.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"
#include "GraphicsManager.h"
#include "InputManager.h"
#include "Box.h"
#include "Position.h"

using namespace std;

GameManager::GameManager() {
    game_over = false;
}

GameManager::GameManager(const GameManager& orig) {
}

GameManager::~GameManager() {

}

bool GameManager::instanceFlag = false;
GameManager* GameManager::single = NULL;

GameManager* GameManager::GetInstance() {
    {
        if (!instanceFlag) {
            single = new GameManager();
            instanceFlag = true;
            return single;
        } else {
            return single;
        }
    }
}

int GameManager::startUp() {
    LogManager::GetInstance()->startUp();
    GraphicsManager *gm = GraphicsManager::GetInstance();
    gm->startUp();
    WorldManager *wm = WorldManager::GetInstance();
    wm->startUp();
    InputManager::GetInstance()->startUp();
    Box b(Position(0,0),gm->getHorizontal(),gm->getVertical());
    wm->setBoundary(b);
    wm->setView(b);
}

void GameManager::shutDown() {

    WorldManager::GetInstance()->shutDown();
    LogManager::GetInstance()->shutDown();
    GraphicsManager::GetInstance()->shutDown();
    InputManager::GetInstance()->shutDown();
}

void GameManager::run(int frame_time) {
    Clock clock; // we instantiate the clock
    WorldManager *w = WorldManager::GetInstance(); // we get the instance of world manager
    GraphicsManager *gr = GraphicsManager::GetInstance();
    InputManager* im = InputManager::GetInstance();
    
    while (!game_over) { // game loop
        clock.delta();
        im->getInput(); //get input from keyboard/mouse
        w->update(); //call update
        w->draw(); //call draw
        gr->swapBuffers(); //swap buffers
        EventStep es;
        onEvent(&es);
        long int loop_time = clock.split(); // get loop time through split
        // sleep time
        struct timespec sleep_time;
        sleep_time.tv_sec = 0;
        sleep_time.tv_nsec = frame_time * 1000000 - loop_time;
        nanosleep(&sleep_time, NULL);
        
        


    }

}

void GameManager::setGameOver(bool game_over) {
    this->game_over = game_over;
}

bool GameManager::getGameOver() const {
    return game_over;
}

int GameManager::getFrameTime() const {
    return frame_time;
}

int GameManager::getStepCount() const {
    return step_count;
}

void GameManager::setHeadless(bool headless) {
    this->headless = headless;
}

bool GameManager::isValid(string event_type) const{
    if (event_type==DF_STEP_EVENT){
        return true;
    }
    return false;
}




