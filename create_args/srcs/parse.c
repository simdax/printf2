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

static char	*ret_val(char type, void *val)
{
	return (m_itoa(
        type == 'd' ? *(int*)val:
        type == 'i' ? *(int*)val:
        type == 'o' ? *(int*)val:
        type == 'u' ? *(int*)val:
        type == 'x' ? *(int*)val:
        type == 'D' ? *(int*)val:
        type == 'I' ? *(int*)val:
        type == 'O' ? *(int*)val:
        type == 'U' ? *(int*)val:
        type == 'X' ? *(int*)val:
		0, 10));	
}
void	parse_value(void *value, char type, t_num *a)
{
    a->value = ret_val(type, value);
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
