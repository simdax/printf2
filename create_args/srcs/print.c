// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   print.cc                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/27 19:30:47 by scornaz           #+#    #+#             //
/*   Updated: 2017/12/18 21:50:37 by simdax           ###   ########.fr       */
//                                                                            //
// ************************************************************************* //

#include "create_args.h"

void	print_arg(t_num *num)
{
  if (num->type == '%')
    {
      write(1, "%", 1);
      ++(num->count);
    }
  else {
    if (num->left)
      print_padding(num->padding, num->type_padding, &num->count);
    if (num->alternate)
      print_alternate(num);
    print_sign(num->sign, &num->count, num->type);
    print_padding(num->precision, num->type_padding, &num->count);
    write(1, num->value, num->str_len);
    if (!num->left)
      print_padding(num->padding, num->type_padding, &num->count);
  }
}

void	print_alternate(t_num *num)
{
  if (ft_strchr("o", num->type))
    num->precision += 1;
  else if (ft_strany(num->type, "x"))
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

void	print_sign(int sign, size_t *c, char type)
{
  if (ft_strany(type, "oxu"))
    return ;
  if (sign == -1)
    {
      ft_putchar('-');
      *c += 1;
    }
  else if (sign == 1) {
    ft_putchar('+');
    *c += 1;
  }
}
