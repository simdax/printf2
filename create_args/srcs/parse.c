#include "create_args.h"

char	*m_itoa(long long val, int base)
{
    char *res;
    char *tmp;
    int	i;

    tmp = (char*)malloc(sizeof(char) * 65);
    tmp[64] = '\0';
    i = 63;
    while (val >= base)
	{
	    tmp[i] = "0123456789abcdef"[val % base];
	    val /= base;
	    i--;
	}
    tmp[i] = "0123456789abcdef"[val % base];
    res = strdup(tmp + i);
    free(tmp);
    return (res);
}

void	parse_value(int value, char type, t_num *a)
{
    a->value = m_itoa(value, 10);
    a->str_len = strlen(a->value);
    a->type = type;
}

void	re_orga(t_num *a)
{
    a->count = 0;
    a->precision = IF(a->precision - a->str_len);
    //a->left = a->padding >= 0;
    a->padding = IF(ABS(a->padding) - a->str_len + a->precision);
}
