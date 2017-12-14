/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:27:21 by scornaz           #+#    #+#             */
/*   Updated: 2017/12/13 16:54:49 by simdax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	dereference(char type, va_list argument, void *val)
{
  if ((ft_strany(type, "diDI")))
    *(int*)val = va_arg(argument, int);
  if ((ft_strany(type, "ouxOUX")))
    *(unsigned int*)val = va_arg(argument, unsigned int);
}

int	flags2print(va_list arg, t_flags flags)
{
  t_num		a;
  void		*value;

  dereference(flags.type, arg, value);
  parse_value(value, flags.type, &a);
  a.left = flags.minus ? 0 : 1;
  a.sign = value > 0;
  a.padding = flags.width;
  a.precision = flags.precision;
  a.alternate = flags.hash;
  a.type_padding = flags.zero ? '0' : ' ';
  a.count = 0;
  a.precision = IF(a.precision - a.str_len);
  a.padding = IF(ABS(a.padding) - a.str_len + a.precision);
  print_arg(&a);
  free(a.value);
  return (a.count);
}


static int		count_percents(const char *str)
{
  int count;

  count = 0;
  while (*str) {
    if (*str == '%') {
      count++;
    }
    str++;
  }
  return (count);
}

int			ft_printf(const char* str, ...)
{
  va_list	arg;
  int		nb_args;
  t_flags	flags;
  char	*cpy;
  int		count;

  count = 0;
  nb_args = count_percents(str);
  if (nb_args){
    va_start(arg, str);
    while (nb_args--) {
      cpy = ft_strchr(str, '%');
      count += cpy - str;
      write(1, str, cpy - str);
      flags = parse(cpy + 1);
      count += flags2print(arg, flags);
      str = cpy + flags.count + 1;
    }
    va_end(arg);
    ft_putstr(str);
  }
  return (count);
}
