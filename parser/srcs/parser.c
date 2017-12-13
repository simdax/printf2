
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */

/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 14:30:39 by scornaz           #+#    #+#             */
/*   Updated: 2017/12/09 18:49:55 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	take_flags(char **s, t_flags *flags)
{
    char		*str = *s;

    while (*str)
	{
	    SET(flags->zero, '0', *str);
	    SET(flags->plus, '+', *str);
	    SET(flags->hash, '#', *str);
	    SET(flags->minus, '-', *str);
	    SET(flags->space, ' ', *str);
	    SET(flags->apostrophe, 39, *str);
	    if (!ft_strany(*str, "0#+- '"))
		break;
	    *s = ++str;
	}
}

t_flags				parse(char *str)
{
    t_flags		flags;
    char		*cpy;

    cpy = str;
    flags = (t_flags){0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    take_flags(&str, &flags);
    flags.width = ft_atoi(str);
    str += flags.width ? ft_nbrsize(flags.width) : 0;
    if (*str == '.')
	{
	    ++str;
	    flags.precision = ft_atoi(str);
	    str += flags.precision ?
		ft_nbrsize(flags.precision) : 0;
	}
    if (*str)
	flags.type = str[0];
    flags.count = str - cpy;
    return (flags);
}
