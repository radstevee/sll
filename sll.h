#include <stdio.h>

#ifndef SLL_H
#define SLL_H

typedef enum {
  DEBUG, INFO, WARN, ERROR
} Level;

typedef char *(*levelstrhandler)(Level);

void initloggingdirat(int fd);
void initloggingdir(const char *dir);
void closelogfile(void);
void logmsg(Level level, const char *format, ...);
void debug(const char *format, ...);
void info(const char *format, ...);
void warn(const char *format, ...);
void error(const char *format, ...);
void setlevelstrhandler(levelstrhandler handler);

#endif // SLL_H
