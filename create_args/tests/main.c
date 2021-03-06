/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 18:53:49 by scornaz           #+#    #+#             */
/*   Updated: 2018/01/16 16:13:57 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_args.h"

void	parse_flags(char *str, t_num *a)
{
  a->base = 10;
  a->sign = 0;
  a->alternate = 0;
  a->left = 1;
  while (*str)
    {
      if (*str == '#')
	a->alternate = 1;
      if (*str == '0')
	a->zero = '0';
      if (*str == '+')
	a->sign = 1;
      if (*str == '-')
	a->left = 0;
      ++str;
    }
}

int	main(int argc, char **argv)
{
  t_num		*a;
  void		*val;

  int b = atoll(argv[1]);
  val = &b;
  (void)argc;
  a = (t_num*)malloc(sizeof(*a));
  ft_bzero(a, sizeof(*a));
  if (parse_value(val, a))
  {
    a->padding = argc > 2 ? atoi(argv[2]) : 0;
    a->precision = argc > 3 ? atoi(argv[3]) : 0;
    if (argc > 4)
      parse_flags(argv[4], a);
    else
      parse_flags("", a);
    re_orga(a);
    print_arg(a);
    free(a->value);	  
  }
}
