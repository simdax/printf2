/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoas.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:38:56 by scornaz           #+#    #+#             */
/*   Updated: 2018/01/26 11:19:38 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char		*s_itoa(intmax_t v, int maj, t_num *a)
{
	char		*res;
	char		*tmp;
	int			i;
	uintmax_t	val;

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
	res = ft_strdup(tmp + i);
	free(tmp);
	return (res);
}

static char		*u_itoa(uintmax_t val, int maj, t_num *a)
{
	char	*res;
	char	*tmp;
	int		i;

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
	res = ft_strdup(tmp + i);
	free(tmp);
	return (res);
}

static void		cast_s(t_num *a, void *val)
{
	if (ft_strequ("hh", a->modifiers))
		a->value = s_itoa(*(char*)val, (int)ft_strchr("DI", a->type), a);
	else if (ft_strequ("h", a->modifiers))
		a->value = s_itoa(*(short*)val, (int)ft_strchr("DI", a->type), a);
	else if (ft_strequ("l", a->modifiers))
		a->value = s_itoa(*(long*)val, (int)ft_strchr("DI", a->type), a);
	else if (ft_strequ("ll", a->modifiers))
		a->value = s_itoa(*(long long*)val, (int)ft_strchr("DI", a->type), a);
	else if (ft_strequ("j", a->modifiers))
		a->value = s_itoa(*(intmax_t*)val, (int)ft_strchr("DI", a->type), a);
	else if (ft_strequ("z", a->modifiers))
		a->value = s_itoa(*(ssize_t*)val, (int)ft_strchr("DI", a->type), a);
	else
		a->value = s_itoa(*(int*)val, (int)ft_strchr("DI", a->type), a);
}

static void		cast_u(t_num *a, void *val)
{
	if (ft_strequ("hh", a->modifiers))
		a->value = u_itoa(*(unsigned char*)val,
						(int)ft_strchr("OUX", a->type), a);
	else if (ft_strequ("h", a->modifiers))
		a->value = u_itoa(*(unsigned short*)val,
						(int)ft_strchr("OUX", a->type), a);
	else if (ft_strequ("l", a->modifiers))
		a->value = u_itoa(*(unsigned long*)val,
						(int)ft_strchr("OUX", a->type), a);
	else if (ft_strequ("ll", a->modifiers))
		a->value = u_itoa(*(unsigned long long*)val,
						(int)ft_strchr("OUX", a->type), a);
	else if (ft_strequ("j", a->modifiers))
		a->value = u_itoa(*(uintmax_t*)val,
						(int)ft_strchr("OUX", a->type), a);
	else if (ft_strequ("z", a->modifiers))
		a->value = u_itoa(*(size_t*)val,
						(int)ft_strchr("OUX", a->type), a);
	else
		a->value = u_itoa(*(unsigned int*)val,
						(int)ft_strchr("OUX", a->type), a);
}

void			itoas(t_num *a, void *val)
{
	if (ft_strchr("diDI", a->type))
		cast_s(a, val);
	else if (ft_strchr("ouxOUXp", a->type))
		cast_u(a, val);
}
