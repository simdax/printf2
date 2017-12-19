/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+   1  */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:27:21 by scornaz           #+#    #+#             */
/*   Updated: 2017/12/19 17:20:00 by simdax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static t_num		flags2print(va_list arg, t_flags flags)
{
  t_num		a;
  uintmax_t	value;

  split_type(flags.type, &a);
  if (a.type == 's')
    a.value = va_arg(arg, char*);
  else
    {
      value = va_arg(arg, uintmax_t);
      parse_value(&value, &a);
    }
  a.left = !flags.minus;
  a.padding = flags.width;
  a.precision = flags.precision;
  a.alternate = flags.hash;
  a.zero = flags.zero;
  re_orga(&a);
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

static int		print(char **str, t_num *nums, int len)
{
  int	count;
  char	*cpy;

  count = 0;
  while (len--) {
    ft_putstr(*str);
    count += ft_strlen(*str);
    ++str;
    print_arg(nums);
    count += nums->count;	  
    ++nums;
  }
  if (str && *str)
    {
      ft_putstr(*str);
      count += ft_strlen(*str);
    }
  return (count);
}

int			ft_printf(const char* str, ...)
{
  va_list	arg;
  int		nb_args;
  char		*cpy;
  char		**stock;
  t_num		*nums;
  t_flags	flags;
  int		count;

  count = 0;
  nb_args = count_percents(str);
  nums = (t_num*)malloc(sizeof(t_num) * (nb_args + 1));
  stock = (char**)malloc(sizeof(char*) * (nb_args + 2));
  if (nb_args){
    va_start(arg, str);
    while (count < nb_args) {
      cpy = ft_strchr(str, '%');
      stock[count] = ft_strsub(str, 0, cpy - str);
      flags = parse(cpy + 1);
      nums[count] = flags2print(arg, flags);
      if (cpy[flags.count] == '%')
        --nb_args;
      str = cpy + flags.count + 1;
      ++count;
    }
    va_end(arg);
  }
  stock[count] = (char*)str;
  return(print(stock, nums, nb_args));
}
