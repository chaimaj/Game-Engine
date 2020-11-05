/* 
 * File:   Clock.cpp
 * Author: PC-Z510
 * 
 * Created on 8 février 2015, 13:00
 */

#include <time.h>
#include "Clock.h"

using namespace std;


Clock::Clock() {
    
    clock_gettime (CLOCK_REALTIME, &prev_ts);
    
}

long int Clock::delta() {
    struct timespec  after_ts;
    clock_gettime (CLOCK_REALTIME, &after_ts);
    
    //compute elapsed time in milliseconds
    long int before_msec = prev_ts.tv_sec*1000 + prev_ts.tv_nsec/1000000;
    long int after_msec = after_ts.tv_sec*1000 + after_ts.tv_nsec/1000000;
    long int elapsed_time = after_msec - before_msec;
    
    prev_ts = after_ts;
    return elapsed_time;
}

long int Clock::split() const{
    struct timespec after_ts;
    clock_gettime (CLOCK_REALTIME, &after_ts);
    
    //compute elapsed time in milliseconds
    long int before_msec = prev_ts.tv_sec*1000 + prev_ts.tv_nsec/1000000;
    long int after_msec = after_ts.tv_sec*1000 + after_ts.tv_nsec/1000000;
    long int elapsed_time = after_msec - before_msec;
    return elapsed_time;
}

Clock::~Clock() {
}


