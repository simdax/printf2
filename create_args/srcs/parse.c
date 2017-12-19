/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simdax </var/spool/mail/simdax>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 23:02:14 by simdax            #+#    #+#             */
/*   Updated: 2017/12/19 12:10:17 by simdax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_args.h"

char	*m_itoa(long long val, int maj, int base)
{
  char *res;
  char *tmp;
  int	i;

  tmp = (char*)malloc(sizeof(char) * 65);
  tmp[64] = '\0';
  i = 63;
  while (val >= base)
    {
      tmp[i] = maj ?
        "0123456789ABCDEF"[val % base] :
        "0123456789abcdef"[val % base];
      val /= base;
      i--;
    }
  tmp[i] = maj ?
    "0123456789ABCDEF"[val % base] :
    "0123456789abcdef"[val % base];
  res = strdup(tmp + i);
  free(tmp);
  return (res);
}

static char	*ret_val(char type, char *mods, void *val, int base)
{
  if (type == '%')
    return ("%");
  if (ft_strchr("diDI", type))
    return (m_itoa(ft_strequ("h", mods) ? *(char*)val:
                   ft_strequ("hh", mods) ? *(short*)val:
                   ft_strequ("l", mods) ? *(long*)val:
                   ft_strequ("ll", mods) ? *(long long*)val:
                   ft_strequ("j", mods) ? *(ssize_t*)val:
                   ft_strequ("z", mods) ? *(intmax_t*)val:
                   *(int*)val,
                   (long)ft_strchr("DI", type), base));
  else if (ft_strchr("ouxOUX", type))
    return (m_itoa(ft_strequ("h", mods) ? *(unsigned char*)val:
                   ft_strequ("hh", mods) ? *(unsigned short*)val:
                   ft_strequ("l", mods) ? *(unsigned long*)val:
                   ft_strequ("ll", mods) ? *(unsigned long long*)val:
                   ft_strequ("j", mods) ? *(size_t*)val:
                   ft_strequ("z", mods) ? *(uintmax_t*)val:
                   *(unsigned int*)val,
                   (long)ft_strchr("OUX", type), base));
  else
    return (0);
}

static int	split_type(char *type, t_num *a)
{
  if (type && ft_strlen(type) == 1)
    {
      a->modifiers = 0;
      a->type = type[0];
    }
  else if (type && (ft_strlen(type) == 2))
    {
      a->modifiers = ft_strsub(type, 0, 1);
      a->type = type[1];
    }
  else if (type && (ft_strlen(type) == 3))
    {
      a->modifiers = ft_strsub(type, 0, 2);
      a->type = type[2];
    }
  else
    return (0);
  return (1);
}

int	parse_value(void *value, char *type, t_num *a)
{
  if (!split_type(type, a))
    return (0);
  a->base =
    ft_strchr("oO", a->type) ? 8:
    ft_strchr("xX", a->type) ? 16:
    10;
  if (value < 0)
    a->sign = -1;
  a->value = ret_val(a->type, a->modifiers, value, a->base);
  a->str_len = ft_strlen(a->value);
  a->count = a->str_len;
  return (1);
}

void	re_orga(t_num *a)
{
  a->precision = IF(a->precision - a->str_len);
  a->padding = IF(ABS(a->padding) - (a->str_len + a->precision));
}
