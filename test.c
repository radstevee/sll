#include "sll.h"

int
main(void)
{
  initloggingdir("test-logs");
  debug("hello");
  info("hello");
  warn("hello");
  error("hello");
  closelogfile();
  return 0;
}
