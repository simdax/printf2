#include "unicode.h"

#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main(int argc, char *argv[])
{
  setlocale(LC_ALL, "");
  printf("size %d and size %d\n", sizeof(*argv[1]), strlen(argv[1]));
  printf("sizeof char %d \n", sizeof(char));
  printf("%s", argv[1]);
  return 0;
}
