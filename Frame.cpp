/* 
 * File:   Frame.cpp
 * Author: PC-Z510
 * 
 * Created on 4 mars 2015, 17:38
 */

#include "Frame.h"

Frame::Frame() {
    width = 0;
    height = 0;
    frame_str = "";
}


/// Create frame of indicated width and height with string.

Frame::Frame(int new_width, int new_height, string frame_str) {
    width = new_width;
    height = new_height;
    this->frame_str = frame_str;
}

/// Set width of frame.

void Frame::setWidth(int new_width) {
    width = new_width;
}

/// Get width of frame.

int Frame::getWidth() const {
    return width;
}

/// Set height of frame.

void Frame::setHeight(int new_height) {
    height = new_height;
}

/// Get height of frame.

int Frame::getHeight() const {
    return height;
}

/// Set frame characters (stored as string).

void Frame::setString(string new_frame_str) {
    frame_str = new_frame_str;
}

/// Get frame characters (stored as string).

string Frame::getString() const {
    return frame_str;
}
