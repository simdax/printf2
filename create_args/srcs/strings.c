/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 18:57:09 by scornaz           #+#    #+#             */
/*   Updated: 2018/01/25 20:02:34 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		strings(t_num *a, va_list arg)
{
	int		character[2];
	void	*string;

	if (a->type == 's')
	{
		string = va_arg(arg, char*);
		a->value = !string ? ft_strdup("(null)") : ft_strdup(string);
	}
	else if (a->type == 'c')
	{
		a->value = malloc(1);
		*(a->value) = va_arg(arg, int);
	}
	else if (a->type == 'S')
	{
		string = va_arg(arg, int*);
		a->value = !string ? ft_strdup("(null)") : transform_utf8(string);
		a->type = 's';
	}
	else if (a->type == 'C')
	{
		character[0] = va_arg(arg, int);
		a->value = transform_utf8(character);
		a->type = 's';
	}
}
