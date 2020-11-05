/* 
 * File:   InputManager.cpp
 * Author: PC-Z510
 * 
 * Created on 18 février 2015, 12:51
 */

#include "InputManager.h"
#include "GraphicsManager.h"
#include "EventMouse.h"
#include "EventKeyboard.h"
#include "LogManager.h"

#include <iostream>

using namespace std;

InputManager::InputManager() {
}

InputManager::InputManager(const InputManager& orig) {
}

bool InputManager::instanceFlag = false;
InputManager* InputManager::single = NULL;
/// Get the one and only instance of the InputManager.

InputManager* InputManager::GetInstance() {
    {
        if (!instanceFlag) {
            single = new InputManager();
            instanceFlag = true;
            return single;
        } else {
            return single;
        }
    }

}


/// Get terminal ready to capture input.  
/// Return 0 if ok, else return negative num.

int InputManager::startUp() {
    if (GraphicsManager::GetInstance()->startUp() != 0) {
        return -1;
    }
    int error = 0;

    //normal terminal input buffers until \n or \n, so disable
    error += cbreak();
    error += nodelay(stdscr, TRUE);

    //disable newline so can detect "enter" key
    error += nonl();

    //turn off the cursor
    error += curs_set(0);

    //disable character echo
    error += noecho();

    //enable mouse events - setup mask with event types accepted
    error += mousemask(BUTTON1_CLICKED, NULL);

    //enable keyboard
    error += keypad(stdscr, TRUE);
    if (error == 0) {
        return 0;
        Manager::setisStarted(true);
    }

    return -1;

}

/// Revert back to normal terminal mode.

void InputManager::shutDown() {
    // Turn on cursor
    curs_set(1);
}

/// Get input from the keyboard and mouse.
/// Pass event along to all interested Objects.

void InputManager::getInput() {
    int key = getch();
    if (key != -1) {

        MEVENT m_event;
        if (key == KEY_MOUSE && getmouse(&m_event)) {
            if (m_event.bstate & BUTTON1_CLICKED) {

                EventMouse mE;
                mE.setMouseX(m_event.x);
                mE.setMouseY(m_event.y);
                mE.setMouseAction(LEFT_BUTTON_CLICK);
                onEvent(&mE);
            }
        } else {
            EventKeyboard keyboardEvent;
            keyboardEvent.setKey(key);
            onEvent(&keyboardEvent);
        }
    }

}

bool InputManager::isValid(string event_type) const{
    if ((event_type==DF_MOUSE_EVENT) || (event_type==DF_KEYBOARD_EVENT)){
        return true;
    }
    return false;
}


