#include "printf.h"
#include <stdio.h>
#include <unistd.h>

int ft_printf(char *str, ...);

void	print(char *s1, long long a, unsigned long long b)
{
  write(1, "moi:\n", 5);
  printf("(%d)", ft_printf(s1, a, b));
  fflush(stdout);
  write(1, "\nvrai:\n", 7);
  printf("(%d)", printf(s1, a, b));
  fflush(stdout);
  write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
  print("coucou %#01.10d les %d loulous", 50, 20);
  print("coucou %#-+01.4u les loulous", 20, 0);
  print("coucou %ld et %lx", 4294967296, 4294967296);
  return (0);
}

