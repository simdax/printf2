/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::	  */
/*	 parser.h											:+:		 :+:	:+:	  */
/*													  +:+ +:+		  +:+	  */
/*	 By: scornaz <marvin@42.fr>						+#+	 +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2017/12/09 14:27:19 by scornaz		   #+#	  #+#			  */
/*   Updated: 2018/01/16 19:08:31 by scornaz          ###   ########.fr       */
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
# include "prototypes_par.h"

#endif
