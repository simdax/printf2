/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 14:27:19 by scornaz           #+#    #+#             */
/*   Updated: 2017/12/09 17:19:49 by scornaz          ###   ########.fr       */
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
    char			type;
    int				count;
}				t_flags;

#define SET(x,c,s)	x = x || s == c

# include <stdio.h>
# include "libft.h"
# include "prototypes.h"

#endif
