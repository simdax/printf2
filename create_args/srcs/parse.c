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

static char	*ret_val(char *type, void *val, int base)
{
	return (m_itoa(
        ft_strcmp(type, "d") ? *(int*)val:
        ft_strcmp(type, "i") ? *(int*)val:
        ft_strcmp(type, "o") ? *(int*)val:
        ft_strcmp(type, "u") ? *(int*)val:
        ft_strcmp(type, "x") ? *(int*)val:
        ft_strcmp(type, "D") ? *(int*)val:
        ft_strcmp(type, "I") ? *(int*)val:
        ft_strcmp(type, "O") ? *(int*)val:
        ft_strcmp(type, "U") ? *(int*)val:
        ft_strcmp(type, "X") ? *(int*)val:
		0, base
		));	
}
void	parse_value(void *value, char *type, t_num *a)
{
	a->base =
        ft_strcmp(type, "o") ? 8:
        ft_strcmp(type, "x") ? 16:
        ft_strcmp(type, "O") ? 8:
        ft_strcmp(type, "X") ? 16:
		10;
    a->value = ret_val(type, value, a->base);
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
