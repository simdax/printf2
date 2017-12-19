// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   print.cc                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/27 19:30:47 by scornaz           #+#    #+#             //
/*   Updated: 2017/12/19 22:15:04 by simdax           ###   ########.fr       */
//                                                                            //
// ************************************************************************* //

#include "create_args.h"

void	print_arg(t_num *num)
{
  if (num->type == '%')
    write(1, "%", 1);
  else {
    if (num->left)
      print_padding(num->padding, num->zero ? '0' : ' ', &num->count);
    if (num->alternate)
      print_alternate(num);
    print_sign(num->sign, &num->count, num->type, num->space);
    print_padding(num->precision, '0', &num->count);
    if (num->type == 's')
      write(1, num->value, num->str_len);
    else
      ft_putstr(num->value);
    if (!num->left)
      print_padding(num->padding, ' ', &num->count);
  }
}

void	print_alternate(t_num *num)
{
  if (ft_strchr("oO", num->type))
    num->precision += 1;
  else if (num->type == 'X')
    write(1, "0X", 2);
  else if (num->type == 'x')
    write(1, "0x", 2);
}

void	print_padding(size_t count, char with, size_t *c)
{
  while (count) {
    ft_putchar(with);
    *c += 1;
    --count;
  }
}

void	print_sign(int sign, size_t *c, char type, int space)
{
  if (sign == -1)
    {
      ft_putchar('-');
      *c += 1;
    }
  else if (sign == 1)
    {
      ft_putchar('+');
      *c += 1;
    }
  else if (space)
    {
      ft_putchar(' ');
      *c += 1;
    }
}
