/* 
 * File:   Position.h
 * Author: PC-Z510
 *
 * Created on 9 février 2015, 15:23
 */

#ifndef POSITION_H
#define	POSITION_H

class Position {
private:
    int x; // Horizontal coordinate
    int y; //Vertical coordinate
    
public:
    //create object with default 2d location (0,0)
    Position();
    // create object with (x,y) location
    Position(int x, int y);
    
    //getters and setters
    void setX(int new_x);
    int getX() const;
    
    void setY(int new_y);
    int getY() const;
    //set h and v coordinates
    void setXY (int new_x,int new_y);



};

#endif	/* POSITION_H */

