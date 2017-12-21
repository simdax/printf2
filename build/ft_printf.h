/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:29:39 by scornaz           #+#    #+#             */
/*   Updated: 2017/12/20 15:55:18 by simdax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _PRINTF_H
# define _PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define ABS(value)	value < 0 ? -value : value
# define IF(value)	value < 0 ? 0 : value
# define SET(a,b,c)	a = a || b == c

typedef struct		s_num
{
  int    		sign;
  int    		alternate; // 0 1
  int			space;
  int    		base;	
  char			type;
  char			*modifiers;
  int			padding; // neg means right
  char			zero; // neg means right
  int	       		left;
  int    		precision; // neg means right
  char			*value;
  int    		str_len; // size of number rep
  size_t		count; // nb of printed letters
}			t_num;

typedef struct		s_flags
{
	int		zero;
	int		plus;
	int		hash;
	int		minus;
	int		apostrophe;
	int		space;
	int		precision;
    	int		width;
  	char		type[3];
  	int		count;
}			t_flags;

# define TYPES		"scdiouxSCDIOUX%"
# define MODIFIERS2	"hl"
# define MODIFIERS1	"jz"

int     ft_printf(const char* str, ...);
t_flags	parse(char *str);
void	choose_itoa(char type, void *val, size_t *c);
void	itoa_base_dioux(unsigned int *i, size_t base, size_t *c);
void	parse_flags(char *str, t_num *a);
int	split_type(char *type, t_num *a);
int	parse_value(void *value, t_num *a);
void	print_alternate(t_num *type);
void	print_arg(t_num *num);
void	print_padding(size_t count, char with, size_t *c);
void	print_sign(int sign, size_t *c, char type, int space);
void	print_value(void *val, char type, size_t *c, size_t precision);
void	re_orga(t_num *a);

#endif
