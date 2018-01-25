#include "printf.h"
#include <stdio.h>
#include <unistd.h>

int ft_printf(char *str, ...);
int ft_sprintf(char *io, char *str, ...);

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

void	print2(char *s1, char *s2, char c)
{
	write(1, "moi:\n", 5);
	printf("(%d)", ft_printf(s1, s2, c));
	fflush(stdout);
	write(1, "\nvrai:\n", 7);
	printf("(%d)", printf(s1, s2, c));
	fflush(stdout);
	write(1, "\n", 1);
}

void	print3(char *s1)
{
	write(1, "moi:\n", 5);
	printf("(%d)", ft_printf(s1));
	fflush(stdout);
	write(1, "\nvrai:\n", 7);
	printf("(%d)", printf(s1));
	fflush(stdout);
	write(1, "\n", 1);
}

#include <limits.h>

int		main(int argc, char **argv)
{
	char io[100];
	int free = 5;
	char c = 'g';

	ft_printf("asdfsad%llAbonhjoue\n", 45);
	ft_printf("\n%s %C %d %p %x %% %S\n", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير");
	ft_printf("%s%d%p%%%S%D%i%o%O%u%U%x%X%c%C\n","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
	ft_sprintf(io, "un truc de fou\n");
	ft_printf("%s", io);
	ft_sprintf(io, "%    d et %p\n", 45, 0);
	ft_printf("%s", io);
	ft_printf("%    p\n", 0);
	ft_printf("%0+5d\n", 42);
	ft_printf("%#o\n", 0);
	print("%-#08x", 42, 0);
	print("%#08x", 42, 0);
	print("coucou %#01.10d les %d loulous", 50, -20);
	ft_printf("%S\n", L"%.0%");
	ft_printf("%S\n", L"%.🙃0%");
	ft_printf("%S\n", L"🔭asd))");
	ft_printf("😘\n");
	print3("%.0%");
	print2("%   %", "test", 0);
	print("%hU", 4294967296, 0);
	print("%U", 4294967296, 0);
	print3("%%");
	print("coucou %#-+01.4u les loulous", 20, 0);
	print("coucou %#-+1.4o les loulous", 20, 0);
	print("coucou %ld et %lx", 4294967296, 4294967296);
	print("%#x", 20, 20);
	print("%jx", -4294967296, 20);
	print("%jd", -4294967296, 20);
	print("%#x", 0, 0);
	print("%0#.x", 0, 0);
	print2("%.2s is a string and a char %c", "", 0);
	print2("%.2s is a string and a char %5c tec", "", 42);
	ft_printf("%*d", 10, 5);
	print("%jd", -9223372036854775808, 0);
	return (0);
}

