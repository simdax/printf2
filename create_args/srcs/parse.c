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
  return (m_itoa(ft_strchr("diDI", type) ? *(int*)val:
		 ft_strchr("ouxOUX", type) ? *(unsigned int*)val:
		 0, base));	
}
int	parse_value(void *value, char *type, t_num *a)
{
  if (type && ft_strlen(type) == 1)
    {
      a->modifiers = 0;
      a->type = type[0];
    }
  else if (type && (ft_strlen(type) == 2))
    {
      a->modifiers = &(type[0]);
      a->type = type[1];
    }
  else if (type && (ft_strlen(type) == 3))
    {
      a->modifiers = ft_strsub(type, 0, 2);
      a->type = type[2];
    }
  else
    return (0);
  a->base =
    ft_strchr("oO", a->type) ? 8:
    ft_strchr("xX", a->type) ? 16:
    10;
  a->value = ret_val(type, value, a->base);
  a->str_len = strlen(a->value);
  return (1);
}

void	re_orga(t_num *a)
{
  a->count = 0;
  a->precision = IF(a->precision - a->str_len);
  //a->left = a->padding >= 0;
  a->padding = IF(ABS(a->padding) - a->str_len + a->precision);
}
