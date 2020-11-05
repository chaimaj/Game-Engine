/* 
 * File:   ViewObject.cpp
 * Author: PC-Z510
 * 
 * Created on 8 mars 2015, 21:00
 */

#include "ViewObject.h"
#include "WorldManager.h"
#include "GraphicsManager.h"
#include "EventView.h"
#include "Position.h"
#include "utility.h"
#include "LogManager.h"

ViewObject::ViewObject() {

    //initialize object attributes
    setSolidness(SPECTRAL);
    setAltitude(DF_MAX_ALTITUDE);
    setType("ViewObject");

    //Initialize ViewObject attributes
    setValue(0);
    setBorder(true);
    setLocation(TOP_CENTER);
    setColor(DF_COLOR_DEFAULT);

    //register interest in view events
    Object::registerInterest(DF_VIEW_EVENT);
}

/// Draw view string and value.
void ViewObject::draw(){
    string temp_str;
    utility u;
    //display view_string + value
    if (border){
        temp_str = " " + getViewString() + " " + u.toString(value) + " ";
    }
    else {
        temp_str = getViewString() + " " + u.toString(value);
    }
    
    //Draw centered at position
    Position pos = u.viewToWorld (getPosition());
    GraphicsManager::GetInstance()->drawString (pos,temp_str,CENTER_JUSTIFIED,getColor());
    
    if (border){
        // Draw a box around display
    }
    
}

  /// Handle "view" event if tag matches view_string (others ignored).
  /// Return 0 if ignored, else 1.
int ViewObject::eventHandler(Event *p_e){
    LogManager *l = LogManager::GetInstance();
    l->writeLog("ViewObject Event handler");
    //see if this is view event
    if (p_e->getType() == DF_VIEW_EVENT){
        l->writeLog("it's an event view");
        EventView *p_ve = static_cast <EventView *> (p_e);
        
        //see if this event is meant for this object
        if (p_ve ->getTag() == getViewString()){
            l->writeLog("check tag");
            if (p_ve->getDelta()){
                setValue (getValue() + p_ve ->getValue()); //Change in value
            }
            else {
                setValue (p_ve->getValue());
            }
            
            //event was handled
            return 1;
        }
    }
    
    return 0;
}

/// Set general location of ViewObject on screen.

void ViewObject::setLocation(ViewObjectLocation new_location) {

    Position p;
    WorldManager *w = WorldManager::GetInstance();
    int delta = 0;
    //Set new position based on location
    switch (new_location) {
        case TOP_LEFT:
            p.setXY(w->getView().getHorizontal()* 1 / 6, 1);
            if (!getBorder()) {
                delta = -1;
            }
            break;
        case TOP_CENTER:
            p.setXY(w->getView().getHorizontal()* 3 / 6, 1);
            if (!getBorder()) {
                delta = -1;
            }
            break;
        case TOP_RIGHT:
            p.setXY(w->getView().getHorizontal()* 5 / 6, 1);
            if (!getBorder()) {
                delta = -1;
            }
            break;
        case BOTTOM_LEFT:
            p.setXY(w->getView().getHorizontal()* 1 / 6, w->getView().getVertical() - 1);
            if (!getBorder()) {
                delta = -1;
            }
            break;
        case BOTTOM_CENTER:
            p.setXY(w->getView().getHorizontal()* 3 / 6, w->getView().getVertical() - 1);
            if (!getBorder()) {
                delta = -1;
            }
            break;
        case BOTTOM_RIGHT:
            p.setXY(w->getView().getHorizontal()* 5 / 6, w->getView().getVertical() - 1);
            if (!getBorder()) {
                delta = -1;
            }
            break;

    }
    
    //shift, as needed, based on border
    p.setY(p.getY()+delta);
    
    //set position of object to new position
    setPosition(p);
    
    //set new Location
    location = new_location;
}

/// Get general location of ViewObject on screen.
ViewObjectLocation ViewObject::getLocation() const{
    return location;
}

  /// Set view value.
  void ViewObject::setValue(int new_value){
      value = new_value;
  }

  /// Get view value.
  int ViewObject::getValue() const{
      return value;
  }

  /// Set view border (true = display border).
  void ViewObject::setBorder(bool new_border){
      border = new_border;
  }

  /// Get view border (true = display border).
  bool ViewObject::getBorder() const{
      return border;
  }

  /// Set view color.
  void ViewObject::setColor(int new_color){
      color = new_color;
  }

  /// Get view color.
  int ViewObject::getColor() const{
      return color;
  }

  /// Set view display string.
  void ViewObject::setViewString(string new_view_string){
      view_string = new_view_string;
  }

  /// Get view display string.
  string ViewObject::getViewString() const{
      return view_string;
  }
  
  /// Serialize ViewObject attributes to a single string.
  /// Only modified attributes (unless all is true).
  string ViewObject::serialize(bool all){
      
  }

  /// Deserialize string to become Object attributes.
  /// Rerturn 0 if no errors, else -1.  
 int ViewObject::deserialize(string s){
     
 }

  /// Return true if attribute modified since last serialize.
bool ViewObject::isModified(enum ViewObjectAttribute attribute) const{
    
}
  
  /// Return true if any attribute modified since last serialize.
bool ViewObject::isModified() const{
    
}







