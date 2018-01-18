/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:52:23 by scornaz           #+#    #+#             */
/*   Updated: 2018/01/18 19:11:18 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"
#include "types_ca.h"
#include "prototypes_ca.h"
#include "libft.h"

void		hydrate(t_num *a, t_flags *flags)
{
	a->left = !flags->minus;
	a->star = flags->star;
	a->padding = flags->width;
	a->precision = flags->precision;
	a->alternate = flags->hash;
	a->zero = flags->zero;
	a->sign = flags->plus;
	a->space = flags->space;
}

void		print_and_free(t_num **nums, char ***str, int *count)
{
	ft_putstr(**str);
	*count += ft_strlen(**str);
	free(**str);
	++(*str);
	print_arg(*nums);
	*count += (*nums)->count;
	if (!ft_strchr("sScC", (*nums)->type))
		free((*nums)->value);
	++(*nums);
}
