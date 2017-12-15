#include "printf.h"

int ft_printf(char *str, ...);

int		main(int argc, char **argv)
{
  ft_printf("coucou %#01.10d les %d loulous", 50, 20);
  return (0);
}

