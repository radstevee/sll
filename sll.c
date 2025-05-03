#include "sll.h"
#include <stdio.h>
#include <stdarg.h>

char *
defaultlevelstrhandler(Level level)
{
  switch (level) {
    case DEBUG: return "[debug]";
    case INFO: return "[info]";
    case WARN: return "[warn]";
    case ERROR: return "[error]";
  };
  return "unknown";
}

static levelstrhandler levelstr = defaultlevelstrhandler;

void
vlog(Level level, const char *format, va_list args)
{
    printf("%s ", levelstr ? levelstr(level) : "unknown");
    vprintf(format, args);
    printf("\n");
}

void
logmsg(Level level, const char *format, ...)
{
  va_list args;
  va_start(args, format);
  vlog(level, format, args);
  va_end(args);
}

void
debug(const char *format, ...)
{
  va_list args;
  va_start(args, format);
  vlog(DEBUG, format, args);
  va_end(args);
}

void
info(const char *format, ...)
{
  va_list args;
  va_start(args, format);
  vlog(INFO, format, args);
  va_end(args);
}

void
warn(const char *format, ...)
{
  va_list args;
  va_start(args, format);
  vlog(WARN, format, args);
  va_end(args);
}

void
error(const char *format, ...)
{
  va_list args;
  va_start(args, format);
  vlog(ERROR, format, args);
  va_end(args);
}

void
setlevelstrhandler(levelstrhandler handler)
{
  levelstr = handler;
}

void
initlogging(void)
{
  setlevelstrhandler(defaultlevelstrhandler);
}

