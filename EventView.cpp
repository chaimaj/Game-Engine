/* 
 * File:   EventView.cpp
 * Author: PC-Z510
 * 
 * Created on 8 mars 2015, 21:38
 */

#include "EventView.h"

/// Create view event with tag VIEW_EVENT, value 0 and delta false.

EventView::EventView() {
    setType(DF_VIEW_EVENT);
    tag = DF_VIEW_EVENT;
    value = 0;
    delta = false;
}

/// Create view event with tag, value and delta as indicated.

EventView::EventView(string new_tag, int new_value, bool new_delta) {
    setType(DF_VIEW_EVENT);
    tag = new_tag;
    value = new_value;
    delta = new_delta;
}

/// Set tag to new tag.

void EventView::setTag(string new_tag) {
    tag = new_tag;
}

/// Get tag.

string EventView::getTag() const {
    return tag;
}

/// Set value to new value.

void EventView::setValue(int new_value) {
    value = new_value;
}

/// Get value.

int EventView::getValue() const {
    return value;
}

/// Set delta to new delta.

void EventView::setDelta(bool new_delta) {
    delta = new_delta;
}

/// Get delta.

bool EventView::getDelta() const {
    return delta;
}
