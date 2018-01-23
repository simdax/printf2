/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:39:36 by scornaz           #+#    #+#             */
/*   Updated: 2018/01/23 12:21:05 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_args.h"

static void	wide_string(t_num *num, t_array *buffer)
{
	char	*result;

	result = transform_utf8((int*)num->value);
	array_add(buffer, result, ft_strlen(result));
}

void		print_arg(t_num *num, t_array *buffer)
{
	if (num->padding && num->left)
		print_padding(num->padding, num->zero ? '0' : ' ', &num->count, buffer);
	if (num->alternate)
		print_alternate(num, buffer);
	print_sign(num->sign, &num->count, num->type, num->space, buffer);
	print_padding(num->precision, '0', &num->count, buffer);
	if (num->type == 's')
		array_add(buffer, num->value, num->str_len);
//		write(1, num->value, num->str_len);
	else if (num->type == 'c')
		array_add(buffer, num->value, 1);
//		write(1, num->value, 1);
	else if (ft_strchr("SC", num->type))
		wide_string(num, buffer);
	else
		array_add(buffer, num->value, num->str_len);
//		ft_putstr(num->value);
	if (num->padding && !num->left)
		print_padding(num->padding, ' ', &num->count, buffer);
}

void		print_alternate(t_num *num, t_array *buffer)
{
	if (num->type == 'X')
		array_add(buffer, "0X", 2);
//		write(1, "0X", 2);
	else if (num->type == 'x')
		array_add(buffer, "0x", 2);
//		write(1, "0x", 2);
}

void		print_padding(size_t count, char with, size_t *c, t_array *buffer)
{
	while (count)
	{
		array_add(buffer, &with, 1);
//		ft_putchar(with);
		*c += 1;
		--count;
	}
}

void		print_sign(int sign, size_t *c, char type, int space, t_array *buffer)
{
	if (sign == -1)
	{
		array_add(buffer, "-", 1);
//		ft_putchar('-');
		*c += 1;
	}
	else if (sign == 1)
	{
		array_add(buffer, "-", 1);
//		ft_putchar('+');
		*c += 1;
	}
	else if (space)
	{
		array_add(buffer, "-", 1);
//		ft_putchar(' ');
		*c += 1;
	}
}
