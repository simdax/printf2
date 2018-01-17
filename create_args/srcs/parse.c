/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::	  */
/*	 parse.c											:+:		 :+:	:+:	  */
/*													  +:+ +:+		  +:+	  */
/*	 By: scornaz <marvin@42.fr>						+#+	 +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2018/01/17 17:14:46 by scornaz		   #+#	  #+#			  */
/*   Updated: 2018/01/17 17:16:11 by scornaz          ###   ########.fr       */
/*																			  */
/* ************************************************************************** */

#include "create_args.h"

int		split_type(char *type, t_num *a)
{
	if (type && ft_strlen(type) == 1)
	{
		a->modifiers = 0;
		a->type = type[0];
	}
	else if (type && (ft_strlen(type) == 2))
	{
		a->modifiers = ft_strsub(type, 0, 1);
		a->type = type[1];
	}
	else if (type && (ft_strlen(type) == 3))
	{
		a->modifiers = ft_strsub(type, 0, 2);
		a->type = type[2];
	}
	else
		return (0);
	return (1);
}

int	parse_value(void *value, t_num *a)
{
	a->base =
		ft_strchr("oO", a->type) ? 8:
		ft_strchr("xX", a->type) ? 16:
		10;
	ret_val(a, value);
	if (a->type != 'c' && ft_strequ(a->value, "0")
		&& a->precision == 0)
	{
		a->value = "";
		if (ft_strchr("xX", a->type))
			a->alternate = 0;
	}
	return (1);
}

void	re_orga(t_num *a)
{
	a->str_len = a->type == 'c' ? 1 : ft_strlen(a->value);
	if (a->type != 'c' && ft_strequ("0", a->value) && ft_strchr("xX", a->type))
		a->alternate = 0;
	if (a->alternate && ft_strchr("xX", a->type))
		a->str_len += 2;
	if (a->type == 's')
	{
		a->str_len = (a->precision == -1 || a->precision > a->str_len) ?
			a->str_len : a->precision;
		a->precision = 0;
	}
	a->count = a->str_len;
	a->precision = IF(a->precision - a->str_len);
	if (a->alternate && ft_strchr("oO", a->type))
		++a->precision;
	if (a->sign != 0 || a->space)
		++a->str_len;
	a->padding = IF(ABS(a->padding) - (a->str_len + a->precision));
	if (a->zero && a->left)
	{
		a->precision = a->padding;
		a->padding = 0;
	}	 
}
