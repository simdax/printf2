

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include "libft.h"

#include "types.h"
#include "prototypes.h"

void	choose_itoa(char type, void *val, size_t *c);
void	itoa_base_dioux(unsigned int *i, size_t base, size_t *c);
//char	*m_itoa(intmax_t val, int base, t_num *a);
void	parse_flags(char *str, t_num *a);
int	split_type(char *type, t_num *a);
int	parse_value(void *value, t_num *a);
void	print_alternate(t_num *type);
void	print_arg(t_num *num);
void	print_padding(size_t count, char with, size_t *c);
void	print_sign(int sign, size_t *c, char type, int space);
void	print_value(void *val, char type, size_t *c, size_t precision);
void	re_orga(t_num *a);
#ifndef __TYPES_H
# define __TYPES_H

# define ABS(value)	value < 0 ? -value : value
# define IF(value)	value < 0 ? 0 : value

typedef struct		s_num
{
	int    		sign;
	int 		star;
	int    		alternate; // 0 1
	int			space;
	int    		base;	
	char		type;
	char		*modifiers;
	int			padding; // neg means right
	char		zero; // neg means right
	int	    	left;
	int    		precision; // neg means right
	char		*value;
	int    		str_len; // size of number rep
	size_t		count; // nb of printed letters
}			t_num;

typedef struct 		s_str
{
	int				padding;
	void			*value;
}					t_str;

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:29:39 by scornaz           #+#    #+#             */
/*   Updated: 2017/11/29 16:42:11 by scornaz          ###   ########.fr       */
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
# include "types.h"
# include "prototypes.h"

#endif
int			ft_printf(const char* str, ...);
/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::	  */
/*	 parser.h											:+:		 :+:	:+:	  */
/*													  +:+ +:+		  +:+	  */
/*	 By: scornaz <marvin@42.fr>						+#+	 +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2017/12/09 14:27:19 by scornaz		   #+#	  #+#			  */
/*   Updated: 2018/01/16 16:45:47 by scornaz          ###   ########.fr       */
/*																			  */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct	s_flags
{
	int			star;
	int			zero;
	int			plus;
	int			hash;
	int			minus;
	int			apostrophe;
	int			space;
	int			precision;
	int			width;
	char		type[3];
	int			count;
}				t_flags;

# define FLAGS		"0#+- '*"
# define TYPES		"scdiouxSCDIOUX%"
# define MODIFIERS2	"hl"
# define MODIFIERS1	"jz"

# include <stdio.h>
# include "libft.h"
# include "prototypes.h"

#endif
t_flags	       	parse(char *str);
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <wchar.h>

int main(int argc, char**argv);
