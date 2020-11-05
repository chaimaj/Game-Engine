/*
 * LogManager.cpp
 *
 *  Created on: 5 févr. 2015
 *      Author: PC-Z510
 */

#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <iostream>
#include <fstream>

#include "LogManager.h"
#include "utility.h"

LogManager::LogManager() {
    // TODO Auto-generated constructor stub

}

LogManager::~LogManager() {
    // TODO Auto-generated destructor stub
}

bool LogManager::instanceFlag = false;
LogManager* LogManager::single = NULL;

LogManager* LogManager::GetInstance() {
    {
        if (!instanceFlag) {
            single = new LogManager();
            instanceFlag = true;
            return single;
        } else {
            return single;
        }
    }
}

int LogManager::startUp() {
    p_f = fopen("LogManager.txt", "w");
}

void LogManager::shutDown() {
    fclose(p_f);
}

int LogManager::writeLog(const char *fmt, ...) {
    utility *u = new utility();
    char * t = u->getTimeString();
    fprintf (p_f, t);
    va_list args;
    va_start(args, fmt);
    vfprintf(p_f, fmt,args);
    fprintf(p_f, "\n");
    //vfprintf(stderr, fmt, args);
    va_end(args);
    if (do_flush){
       fflush(p_f); 
    }
    
}

void LogManager::setFlush(bool do_flush){
    this->do_flush = do_flush;
}




