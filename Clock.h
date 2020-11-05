/* 
 * File:   Clock.h
 * Author: PC-Z510
 *
 * Created on 8 février 2015, 13:00
 */
#include <time.h>

#ifndef CLOCK_H
#define	CLOCK_H

class Clock {
private:
    struct timespec prev_ts; // Stores previous time delta() called
    
public:
    //Sets prev_ts to current time
    Clock();
   // Return time elpased since delta() was last called
   // Units are microseconds
    long int delta(void);
   // Return time elapsed since delta() was last called
   // Units are microseconds
    long int split(void) const;
    
    virtual ~Clock();


};

#endif	/* CLOCK_H */

