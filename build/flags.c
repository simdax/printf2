/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simdax </var/spool/mail/simdax>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:48:34 by simdax            #+#    #+#             */
/*   Updated: 2017/12/19 15:30:46 by simdax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
  while (*str && i < 3 && (ft_strany(*str, MODIFIERS1) ||
                           ft_strany(*str, MODIFIERS2) ||
                           ft_strany(*str, TYPES)))
    {
      if ((i && ft_strany(flags[i - 1], TYPES)) ||
          (ft_strchr(MODIFIERS1, *str) && i != 0) ||
          (ft_strchr(MODIFIERS2, *str) && i > 1 &&
           !ft_strchr(MODIFIERS2, flags[0])))
        return ;
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
  flags = (t_flags){0, 0, 0, 0, 0, 0, -1, 0, 0, 0};
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