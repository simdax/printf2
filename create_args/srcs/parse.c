/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::	  */
/*	 parse.c											:+:		 :+:	:+:	  */
/*													  +:+ +:+		  +:+	  */
/*	 By: simdax </var/spool/mail/simdax>			+#+	 +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2017/12/18 23:02:14 by simdax			   #+#	  #+#			  */
/*   Updated: 2018/01/16 16:49:34 by scornaz          ###   ########.fr       */
/*																			  */
/* ************************************************************************** */

#include "create_args.h"

static char	*s_itoa(intmax_t v, int maj, t_num *a)
{
	char *res;
	char *tmp;
	int	i;
	uintmax_t val;
  
	tmp = (char*)malloc(sizeof(char) * 65);
	if (v < 0)
		a->sign = -1;
	val = v < 0 ? -v : v;
	tmp[64] = '\0';
	i = 63;
	while (val >= a->base)
	{
		tmp[i] = maj ?
			"0123456789ABCDEF"[val % a->base] :
			"0123456789abcdef"[val % a->base];
		val /= a->base;
		i--;
	}
	tmp[i] = maj ?
		"0123456789ABCDEF"[val % a->base] :
		"0123456789abcdef"[val % a->base];
	res = strdup(tmp + i);
	free(tmp);
	return (res);
}

static char	*u_itoa(uintmax_t val, int maj, t_num *a)
{
	char *res;
	char *tmp;
	int	i;

	tmp = (char*)malloc(sizeof(char) * 65);
	tmp[64] = '\0';
	i = 63;
	while (val >= a->base)
	{
		tmp[i] = maj ?
			"0123456789ABCDEF"[val % a->base] :
			"0123456789abcdef"[val % a->base];
		val /= a->base;
		i--;
	}
	tmp[i] = maj ?
		"0123456789ABCDEF"[val % a->base] :
		"0123456789abcdef"[val % a->base];
	res = strdup(tmp + i);
	free(tmp);
	return (res);
}

static void	ret_val(t_num *a, void *val)
{
	if (a->type == '%')
		a->value = "%";
	else if (ft_strchr("diDI", a->type))
		a->value = s_itoa(ft_strequ("hh", a->modifiers) ? *(char*)val:
						  ft_strequ("h", a->modifiers) ? *(short*)val:
						  ft_strequ("l", a->modifiers) ? *(long*)val:
						  ft_strequ("ll", a->modifiers) ? *(long long*)val:
						  ft_strequ("j", a->modifiers) ? *(intmax_t*)val:
						  ft_strequ("z", a->modifiers) ? *(ssize_t*)val:
						  *(int*)val,
						  (long)ft_strchr("DI", a->type), a);
	else if (ft_strchr("ouxOUX", a->type))
		a->value = u_itoa(ft_strequ("h", a->modifiers) ? *(unsigned char*)val:
						  ft_strequ("hh", a->modifiers) ? *(unsigned short*)val:
						  ft_strequ("l", a->modifiers) ? *(unsigned long*)val:
						  ft_strequ("ll", a->modifiers) ? *(unsigned long long*)val:
						  ft_strequ("j", a->modifiers) ? *(uintmax_t*)val:
						  ft_strequ("z", a->modifiers) ? *(size_t*)val:
						  *(unsigned int*)val,
						  (long)ft_strchr("OUX", a->type), a);
	else
		a->value = *(int*)val;
}

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
