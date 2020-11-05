/* 
 * File:   Sprite.cpp
 * Author: PC-Z510
 * 
 * Created on 4 mars 2015, 17:38
 */

#include "Sprite.h"
#include "GraphicsManager.h"

Sprite::Sprite() {
}

Sprite::~Sprite() {
    if (frame != NULL) {
        delete [] frame;
    }
}

/// Create sprite with indicated maximum number of frames.

Sprite::Sprite(int max_frames) {
    frame_count = 0;
    width = 0;
    height = 0;
    frame = new Frame [max_frames];
    max_frame_count = max_frames;
    color = DF_COLOR_DEFAULT;
}

/// Set width of sprite.

void Sprite::setWidth(int new_width) {
    width = new_width;
}

/// Get width of sprite.

int Sprite::getWidth() const {
    return width;
}

/// Set height of sprite.

void Sprite::setHeight(int new_height) {
    height = new_height;
}

/// Get height of sprite.

int Sprite::getHeight() const {
    return height;
}

/// Set sprite color.

void Sprite::setColor(int new_color) {
    color = new_color;
}

/// Get sprite color.

int Sprite::getColor() const {
    return color;
}

/// Get total count of frames in sprite.

int Sprite::getFrameCount() const {
    return frame_count;
}

/// Add frame to sprite.
/// Return -1 if frame array full, else 0.

int Sprite::addFrame(Frame new_frame) {
    if (frame_count == max_frame_count){
        return -1;
    }
    else {
        frame[frame_count]=new_frame;
        frame_count++;
    }
}

/// Get next sprite frame indicated by number.
/// Return empty frame if out of range [0, frame_count].

Frame Sprite::getFrame(int frame_number) const {
    if ((frame_number<0) || (frame_number >= frame_count)){
        Frame empty;
        return empty;
    }
    return frame[frame_number];
}

/// Set label associated with sprite.

void Sprite::setLabel(string new_label) {
    label=new_label;
}

/// Get label associated with sprite.

string Sprite::getLabel() const {
    return label;
}

