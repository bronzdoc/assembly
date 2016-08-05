#include <string.h>

int
main()
{
  char* str = "hello world\n";
  int len = strlen(str);
  printFromAsm(str, len);
  return 0;
}
