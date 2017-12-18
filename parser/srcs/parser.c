/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simdax </var/spool/mail/simdax>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:48:34 by simdax            #+#    #+#             */
/*   Updated: 2017/12/18 18:44:18 by simdax           ###   ########.fr       */
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

static void	take_type(char **s, char *flags)
{
  char	*str;
  int	i;

  i = 0;
  str = *s;
  while (*str && (ft_strany(*str, MODIFIERS) || ft_strany(*str, TYPES)))
    {
      if (ft_strany(*str, MODIFIERS))
	{
	  if (i && ft_strchr(TYPES, flags[i - 1]))
	    return ;
	  if (i == REPS && flags[i - 1] == flags[i])
	    {
	      flags[i] = *str;
	      continue;
	    }
	  else if (i > REPS)
	    {
	      *flags = 0;
	      break;
	    }
	}
      flags[i] = *str;
      *s = ++str;
      ++i;
    }
}

t_flags				parse(char *str)
{
  t_flags	flags;
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
    take_type(&str, flags.type);
  flags.count = str - cpy;
  return (flags);
}
