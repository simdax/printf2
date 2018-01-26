/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:29:39 by scornaz           #+#    #+#             */
/*   Updated: 2018/01/25 21:18:48 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PRINTF_H
# define _PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include "parser.h"
# include "create_args.h"
# include "prototypes_ca.h"

typedef struct	s_args {
	int			nb_args;
	char		*cpy;
	char		**stock;
	t_num		*nums;
	t_flags		flags;
	int			count;
}				t_args;

typedef struct	s_prout
{
	char		**str;
	t_num		*nums;
	int			len;
	const char	*last;
}				t_prout;

t_num			flags2print(va_list arg, t_flags flags);
int				count_percents(const char *str);
void			init_args(t_args *args, const char *str);
int				ft_printf(const char *str, ...);
char			*ft_sprintf(char *io, const char *str, ...);
int				print_and_free(t_num **nums, char ***str, t_array *buffer);
void			hydrate(t_num *a, t_flags *flags);

#endif
