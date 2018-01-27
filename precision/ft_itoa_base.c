/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 12:07:17 by scornaz           #+#    #+#             */
/*   Updated: 2018/01/27 12:37:46 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
	
#define BASE  "0123456789ABCDEF"
#include <stdlib.h>

char    *ft_itoa_base(int value, int base)
{
	char *res;
	int i = 33;
	int neg = 0;

	res = malloc(i);
	res[i--] = 0;
	if (value < 0)
	{
		neg = 1;
		value *= -1;
	}
	while (value >= base)
	{
		res[i] = BASE[value % base];
		--i;
		value /= base;
	}
	res[i] = BASE[value % base];
	if (!neg)
		res[--i] = '0';
	return (res + i);
}
