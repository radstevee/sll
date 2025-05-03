#ifndef SLL_H
#define SLL_H

typedef enum {
  DEBUG, INFO, WARN, ERROR
} Level;

typedef char *(*levelstrhandler)(Level);

void logmsg(Level level, const char *format, ...);
void debug(const char *format, ...);
void info(const char *format, ...);
void warn(const char *format, ...);
void error(const char *format, ...);
void setlevelstrhandler(levelstrhandler handler);
void initlogging(void);

#endif // SLL_H
