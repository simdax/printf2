	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:27:21 by scornaz           #+#    #+#             */
/*   Updated: 2017/12/15 18:23:07 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

typedef union   u_tt
{
  int		i;
  unsigned int 	u;
}		t_tt;


void	dereference(char type, va_list argument, void *val)
{
  t_tt tt;
  
  if ((ft_strany(type, "diDI")))
    {
      tt.i = va_arg(argument, int);
      *(int*)val = tt.i;
    }
  if ((ft_strany(type, "ouxOUX")))
    {
      tt.u = va_arg(argument, unsigned int);
      *(unsigned int*)val = tt.u;
    }
}

t_num	flags2print(va_list arg, t_flags flags)
{
  t_num		a;
  void		*value;

  value = malloc(32);
  dereference('d', arg, value);
  parse_value(value, flags.type, &a);
  a.left = flags.minus ? 0 : 1;
  a.sign = value > 0;
  a.padding = flags.width;
  a.precision = flags.precision;
  a.alternate = flags.hash;
  a.type_padding = flags.zero && !ft_strchr("DIOUXdioux", a.type) ? '0' : ' ';
  a.count = 0;
  a.precision = IF(a.precision - a.str_len);
  a.padding = IF(ABS(a.padding) - a.str_len + a.precision);
  print_arg(&a);
//  free(a.value);
  // free(value);
  return (a);
}


static int		count_percents(const char *str)
{
  int count;

  count = 0;
  while (*str) {
    if (*str == '%')
      count++;
    str++;
  }
  return (count);
}

int			ft_printf(const char* str, ...)
{
  va_list	arg;
  int		nb_args;
  char		*cpy;
  int		count;
  t_num		*nums;
  t_flags flags;
    
  count = 0;
  nb_args = count_percents(str);
  nums = (t_num*)malloc(sizeof(t_num) * nb_args + 1);
  if (nb_args){
    va_start(arg, str);
    while (nb_args--) {
      cpy = ft_strchr(str, '%');
      count += cpy - str;
      //write(1, str, cpy - str);
	  flags = parse(cpy + 1);
	  *nums = flags2print(arg, flags);
	  count += nums->count;	  
	  str = cpy + flags.count + 1;
	  nums++;
    }
	   va_end(arg);
    ft_putstr(str);
  }
  return (count);
}
