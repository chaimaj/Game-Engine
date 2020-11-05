/* 
 * File:   utility.h
 * Author: PC-Z510
 *
 * Created on 5 février 2015, 19:01
 */



#ifndef UTILITY_H
#define	UTILITY_H

#include "Position.h"
#include "Box.h"
#include "Object.h"

class utility {
public:
    
    utility();
    utility(const utility& orig);
    virtual ~utility();
    char *getTimeString();
    bool positionIntersect(Position p1, Position p2);
    bool boxIntersectsBox(Box A, Box B);
    Box getWorldBox(Object *p_o);
    Box getWorldBox(Object* p_o, Position where);
    Position worldToView (Position world_pos);
    Position viewToWorld (Position view_pos);
    string toString (int i);

private:

};

#endif	/* UTILITY_H */

