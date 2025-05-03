#include "sll.h"

int
main(void)
{
  initlogging();
  debug("hello");
  info("hello");
  warn("hello");
  error("hello");
  return 0;
}
