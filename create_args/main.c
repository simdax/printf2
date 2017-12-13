/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 18:53:49 by scornaz           #+#    #+#             */
/*   Updated: 2017/12/08 18:54:39 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_args.h"

void	parse_flags(char *str, t_num *a)
{
    a->type_padding = ' ';
    a->sign = 0;
    a->alternate = 0;
    a->left = 1;
    while (*str)
	{
	    if (*str == '#')
		a->alternate = 1;
	    if (*str == '0')
		a->type_padding = '0';
	    if (*str == '+')
		a->sign = 1;
	    if (*str == '-')
		a->left = -1;
	    ++str;
	}
}

int	main(int argc, char **argv)
{
	t_num		*a;

	(void)argc;
	a = (t_num*)malloc(sizeof(*a));
	parse_value(atoi(argv[1]), 'd', a);
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
