/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simdax </var/spool/mail/simdax>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:48:34 by simdax            #+#    #+#             */
/*   Updated: 2018/01/16 16:43:48 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void set(int *flag, char c1, char c2)
{
	*flag = *flag || c1 == c2;
}

static void	take_flags(char **s, t_flags *flags)
{
	char		*str = *s;

	while (*str)
    {
		set(&flags->star, '*', *str);
		set(&flags->zero, '0', *str);
		set(&flags->plus, '+', *str);
		set(&flags->hash, '#', *str);
		set(&flags->minus, '-', *str);
		set(&flags->space, ' ', *str);
		set(&flags->apostrophe, 39, *str);
		if (!ft_strchr(FLAGS, *str))
			break;
		*s = ++str;
    }
}

static void	take_type(char **s, char *flags)
{
	char	*str;
	int	i;

	i = 0;
	str = *s;
	while (*str && i < 3 && (ft_strany(*str, MODIFIERS1) ||
							 ft_strany(*str, MODIFIERS2) ||
							 ft_strany(*str, TYPES)))
    {
		if ((i && ft_strany(flags[i - 1], TYPES)) ||
			(ft_strchr(MODIFIERS1, *str) && i != 0) ||
			(ft_strchr(MODIFIERS2, *str) && i > 1 &&
			 !ft_strchr(MODIFIERS2, flags[0])))
        {
			if (!ft_strchr(TYPES, flags[i - 1]))
				flags[i] = 'E';
			return ;
        } 
		flags[i] = *str;
		*s = ++str;
		++i;
    }
	if (!i || !ft_strchr(TYPES, flags[i - 1]))
		flags[i] = 'E';
}

t_flags				parse(char *str)
{
	t_flags	flags;
	char		*cpy;

	cpy = str;
	flags = (t_flags){0, 0, 0, 0, 0, 0, 0, -1, 0, "E", 0};
	take_flags(&str, &flags);
	flags.width = ft_atoi(str);
	str += flags.width ? ft_nbrsize(flags.width) : 0;
	if (*str == '.')
    {
		++str;
		flags.precision = ft_atoi(str);
		str += flags.precision ?
			ft_nbrsize(flags.precision) :
			str[0] == '0' ? 1 : 0;
    }
	if (*str)
		take_type(&str, flags.type);
	flags.count = str - cpy;
	return (flags);
}
