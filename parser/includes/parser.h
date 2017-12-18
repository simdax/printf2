/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 14:27:19 by scornaz           #+#    #+#             */
/*   Updated: 2017/12/18 18:35:12 by simdax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PARSER_H
# define PARSER_H

typedef struct	s_flags
{
	int			zero;
	int			plus;
	int			hash;
	int			minus;
	int			apostrophe;
	int			space;
	int			precision;
    	int			width;
  	char			type[3];
  	int			count;
}				t_flags;

# define SET(x,c,s)	x = x || s == c
# define TYPES		"diouxDIOUX%"
# define MODIFIERS	"hl"
# define REPS		1

# include <stdio.h>
# include "libft.h"
# include "prototypes.h"

#endif
