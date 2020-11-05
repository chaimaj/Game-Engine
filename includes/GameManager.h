/* 
 * File:   GameManager.h
 * Author: PC-Z510
 *
 * Created on 5 février 2015, 19:43
 */

#ifndef GAMEMANAGER_H
#define	GAMEMANAGER_H

#include <time.h>
#include "Manager.h"
#define DF_DEFAULT_FRAME_TIME 33

class GameManager : public Manager {
private:
    GameManager();
    GameManager(GameManager const &copy);
    void operator=(GameManager const&);

    bool game_over; ///< True -> game loop should stop.
    int frame_time; ///< Target time per game loop, in millisec.
    int step_count; ///< Count game loop iterations.
    bool headless; ///< True if run without graphics or input.
    
    static bool instanceFlag;
    static GameManager *single;

public:
    bool isValid(string event_type) const;
    
    virtual ~GameManager();
    
    static GameManager* GetInstance();
    
    //Return 0 if ok, else negative number
    virtual int startUp();

    //Shutdown Manager
    virtual void shutDown();
    
    void run(int frame_time = DF_DEFAULT_FRAME_TIME);

    /// Set game over status to indicated value.
    /// If true (default), will stop game loop.
    void setGameOver(bool game_over = true);

    /// Get game over status.
    bool getGameOver() const;

    /// Return frame time.  
    /// Frame time is target time for each game loop, in milliseconds.
    int getFrameTime() const;

    /// Return game loop step count.
    int getStepCount() const;

    /// If true before startUp(), do not start InputManager 
    /// or GraphicsManager.
    void setHeadless(bool headless = true);


};

#endif	/* GAMEMANAGER_H */

