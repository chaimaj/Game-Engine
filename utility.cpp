/* 
 * File:   utility.cpp
 * Author: PC-Z510
 * 
 * Created on 5 février 2015, 19:01
 */

#include <cstdlib>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>
#include <sstream>
#include "utility.h"
#include "Box.h"
#include "Object.h"
#include "WorldManager.h"
#include "LogManager.h"

using namespace std;

utility::utility() {
}

utility::utility(const utility& orig) {
}

utility::~utility() {
}

char * utility::getTimeString() {
    //String to return, made 'static' so persists
    static char time_str[30];
    //System calls to get time
    time_t now;
    time(&now);
    struct tm *p_time = localtime(&now);

    //'02' gives two digits, '%d' for integers
    sprintf(time_str, "%02d:%02d:%02d", p_time -> tm_hour, p_time ->tm_min, p_time ->tm_sec);

    return time_str;
}

bool utility::positionIntersect(Position p1, Position p2) {
    if ((p1.getX() == p2.getX())&&(p1.getY() == p2.getY())) {
        return true;
    }
    return false;
}

//return true if intersect, else false

bool utility::boxIntersectsBox(Box A, Box B) {
    LogManager *l = LogManager::GetInstance();
    int Bx1 = B.getCorner().getX();
    int By1 = B.getCorner().getY();
    int Bx2 = B.getCorner().getX() + B.getVertical() - 1;
    int By2 = B.getCorner().getY() + B.getHorizontal() - 1;
    
    int Ax1 = A.getCorner().getX();
    int Ay1 = A.getCorner().getY();
    int Ax2 = A.getCorner().getX() + A.getVertical() - 1;
    int Ay2 = A.getCorner().getY() + A.getHorizontal() - 1;
    
    bool x_overlap = false;
    bool y_overlap = false;

    //Test horizontal overlap (x_overlap)
    if (((Bx1 <= Ax1) && (Ax1 <= Bx2)) || ((Ax1 <= Bx1) && (Bx1 <= Ax2))) {
        x_overlap = true;
    }

    if (((By1 <= Ay1) && (Ay1 <= By2)) || ((Ay1 <= By1)&& (By1 <= Ay2))) {
        y_overlap = true;
    }
    //Text vertcial overlap (y_overlap)
    if ((x_overlap) && (y_overlap)) {
        return true;
    } else {
        return false;
    }
}

//convert relative bounding Box for object to absolute world Box

Box utility::getWorldBox(Object* p_o) {
    Box temp_box = p_o->getBox();
    Position corner = temp_box.getCorner();
    corner.setX(corner.getX() + p_o->getPosition().getX());
    corner.setY(corner.getY() + p_o->getPosition().getY());
    temp_box.setCorner(corner);

    return temp_box;
}

Box utility::getWorldBox(Object* p_o, Position where) {
    Box temp_box = p_o->getBox();
    Position corner = temp_box.getCorner();
    corner.setX(corner.getX() + where.getX());
    corner.setY(corner.getY() + where.getY());
    temp_box.setCorner(corner);

    return temp_box;
}

//convert world position to view position

Position utility::worldToView(Position world_pos) {
    Position view_origin = WorldManager::GetInstance()->getView().getCorner();
    int view_x = view_origin.getX();
    int view_y = view_origin.getY();
    Position view_pos(world_pos.getX() - view_x, world_pos.getY() - view_y);

    return view_pos;
}

Position utility::viewToWorld (Position view_pos){
    Position view_origin = WorldManager::GetInstance()->getView().getCorner();
    int view_x = view_origin.getX();
    int view_y = view_origin.getY();
    Position world_pos(view_pos.getX() + view_x, view_pos.getY() + view_y);
    
    return world_pos;
}

string utility::toString (int i){
    stringstream ss;
    ss << i;
    return ss.str();
}

