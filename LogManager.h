
#ifndef __LOG_MANAGER_H__
#define __LOG_MANAGER_H__

#include <stdio.h>
#include "Manager.h"
//#include "utility.h"

#define DF_LOGFILE_NAME "dragonfly.log"

class LogManager : public Manager {

 private:
  static bool instanceFlag;
  static LogManager *single;
  LogManager();                      ///< Private since a singleton.
  LogManager (LogManager const&);    ///< Don't allow copy.
  void operator=(LogManager const&); ///< Don't allow assignment.
  bool do_flush;                     ///< True if flush after each write.
  FILE *p_f;                         ///< Pointer to logfile.
      
  bool log_time_string;              ///< True if prepend time.
  bool log_step_count;               ///< True if prepend step count.

 public:
  static LogManager* GetInstance();
  /// If logfile is open, close it.
  ~LogManager();

  /// Start up LogManager (open logfile "dragonfly.log").
  int startUp();

  /// Shut down LogManager (close logfile).
  void shutDown();

  /// Write to logfile.
  /// Supports printf() formatting of strings.
  /// Return bytes written (excluding prepends), -1 if error.
  int writeLog(const char *fmt, ...);
  
  
  /// Set flush of logfile after each write.
  void setFlush(bool do_flush=true);

  // return a nicely formatted string
  //char *getTimeString();
};

#endif // __LOG_MANAGER_H__
