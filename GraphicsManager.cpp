/* 
 * File:   GraphicsManager.cpp
 * Author: PC-Z510
 * 
 * Created on 15 février 2015, 19:47
 */

#include "GraphicsManager.h"
#include "Frame.h"
#include "utility.h"
#include <iostream>

using namespace std;

GraphicsManager::GraphicsManager() {
}

bool GraphicsManager::instanceFlag = false;
GraphicsManager* GraphicsManager::single = NULL;

GraphicsManager* GraphicsManager::GetInstance() {
    {
        if (!instanceFlag) {
            single = new GraphicsManager();
            instanceFlag = true;
            return single;
        } else {
            return single;
        }
    }
}

int GraphicsManager::startUp() {
    int error = 0;
    //enable curses
    initscr();

    p_buffer = buffer1;

    //Make full size windows
    buffer1 = newwin(0, 0, 0, 0);
    buffer2 = newwin(0, 0, 0, 0);

    //Get terminal dimensions
    getmaxyx(stdscr, max_y, max_x);

    //Make charachters bold
    //(Bold characters make graphics more vivid)
    error += wattron(buffer1, A_BOLD);
    error += wattron(buffer2, A_BOLD);

    //Make next refresh redraw window completely
    error += clearok(buffer1, TRUE);
    error += clearok(buffer2, TRUE);

    //LEave cursor where it is after refresh
    error += leaveok(buffer1, TRUE);
    error += leaveok(buffer2, TRUE);

    //Check if the terminal supports color
    if (has_colors()) {
        //enable color
        start_color();
        //setup colors pairs prior to use: init_pair (num,fg,bg)
        init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK);
        init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_BLACK);
        init_pair(COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK);
        init_pair(COLOR_BLUE, COLOR_BLUE, COLOR_BLACK);
        init_pair(COLOR_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(COLOR_CYAN, COLOR_CYAN, COLOR_BLACK);
        init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);

    }
    if (error == 0) {
        Manager::setisStarted(true);
        return 0;
    } else {
        Manager::setisStarted(false);
        return 1;
    }

}
//draw character at screen location (x,y) with color
//return 0 if ok else 1

int GraphicsManager::drawCh(Position world_pos, char ch, int color) const {
    utility u;
    Position view_pos = u.worldToView (world_pos);
    
    //if drawing in color, turn on colornpair 'color'
    wattron(p_buffer, COLOR_PAIR(color));
    //draw single character at (x,y)
    mvwaddch(p_buffer, view_pos.getY(), view_pos.getX(), ch);
    //if drew in color, turn off color pair 'color'
    wattroff(p_buffer, COLOR_PAIR(color));

}

int GraphicsManager::drawString(Position world_pos, string str, Justification just, int color) const {
    Position starting_pos = world_pos;
    switch (just) {
        case CENTER_JUSTIFIED:
            starting_pos.setX(world_pos.getX() - str.size() / 2);
            break;
        case RIGHT_JUSTIFIED:
            starting_pos.setX(world_pos.getX() - str.size());
            break;
        case LEFT_JUSTIFIED:
        default:
            break;
    }
    // draw character by character
    for (int i = 0; i < str.size(); i++) {
        Position temp_pos(starting_pos.getX() + i, starting_pos.getY());
        drawCh(temp_pos, str[i], color);
    }
}

int GraphicsManager::drawFrame(Position world_pos, Frame frame, bool centered, int color, char transparent) const {
    int x_offset = 0;
    int y_offset = 0;
    //check for empty frame
    if (frame.getString() == "") {
        return -1;
    }

    //Centered ? then offset (x,y) by 1/2 (width/height)
    if (centered) {
        x_offset = frame.getWidth() / 2;
        y_offset = frame.getHeight() / 2;
    } else {
        x_offset = 0;
        y_offset = 0;
    }

    //frame data stored in String
    string str = frame.getString();

    //draw character by character
    for (int y = 0; y < frame.getHeight(); y++) {
        for (int x = 0; x < frame.getWidth(); x++) {
            Position temp_pos(world_pos.getX()- x_offset + x, world_pos.getY() - y_offset + y);
            drawCh (temp_pos, str[y * frame.getWidth()+x], color);
        }
    }
}



/// Return curses window that has been most recently drawn and refreshed.

WINDOW * GraphicsManager::getPreviousBuffer() const {
    if (p_buffer == buffer1) {
        return buffer2;
    } else {

        return buffer1;
    }
}

/// Return curses window that is being drawn to but not yet refreshed.

WINDOW * GraphicsManager::getCurrentBuffer() const {

    return p_buffer;
}

int GraphicsManager::swapBuffers() {


    wrefresh(p_buffer);

    if (p_buffer == buffer1) {
        p_buffer = buffer2;
    } else {

        p_buffer = buffer1;
    }
    //clearok(p_buffer, TRUE);
    //clear();
    werase(p_buffer);



}

void GraphicsManager::clean() const {

    wclear(getPreviousBuffer());
}

/// Return display's horizontal maximum.

int GraphicsManager::getHorizontal() const {
    int maxX, maxY;
            getmaxyx(stdscr, maxY, maxX);

    return maxX;
}

/// Return display's vertical maximum.

int GraphicsManager::getVertical() const {
    int maxX, maxY;
            getmaxyx(stdscr, maxY, maxX);

    return maxY;
}

void GraphicsManager::shutDown() {
    endwin();
}

bool GraphicsManager::isValid(string event_type) const{
    
}



