/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::	  */
/*	 main.c												:+:		 :+:	:+:	  */
/*													  +:+ +:+		  +:+	1  */
/*	 By: scornaz <marvin@42.fr>						+#+	 +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2017/11/24 14:27:21 by scornaz		   #+#	  #+#			  */
/*   Updated: 2018/01/18 09:59:02 by scornaz          ###   ########.fr       */
/*																			  */
/* ************************************************************************** */

#include "printf.h"

static void	hydrate(t_num *a, t_flags *flags)
{
	a->left = !flags->minus;
	a->star = flags->star;
	a->padding = flags->width;
	a->precision = flags->precision;
	a->alternate = flags->hash;
	a->zero = flags->zero;
	a->sign = flags->plus;
	a->space = flags->space;
}

static t_num		flags2print(va_list arg, t_flags flags)
{
	t_num		a;
	intmax_t	value;
	char		*string;

	hydrate(&a, &flags);
	split_type(flags.type, &a);
	re_orga2(&a);
	if (a.type == 's')
	{
		string = va_arg(arg, char*);
		a.value = !string ? "(null)" : string;
	}
	else
	{
		value = va_arg(arg, intmax_t);
		parse_value(&value, &a);
	}
	re_orga(&a);
	return (a);
}

static int		print(char **str, t_num *nums, int len, const char *last)
{
	int		count;
	char	**cpy;
	t_num	*cpy_nums;

	cpy = str;
	cpy_nums = nums;
	count = 0;
	while (len--) {
		ft_putstr(*str);
		count += ft_strlen(*str);
		free(*str);
		++str;
		print_arg(nums);
		count += nums->count;
		if (!ft_strchr("sScC", nums->type))
			free(nums->value);
		++nums;
	}
	if (str && *str)
	{
		ft_putstr(*str);
		count += ft_strlen(*str);
		if (*str != last)
			free(*str);
	}
	free(cpy);
	free(cpy_nums); 
	return (count);
}

static int		count_percents(const char *str)
{
	int count;

	count = 0;
	while (*str) {
		if (*str == '%')
			count++;
		str++;
	}
	return (count);
}

typedef struct	s_args {
	int			nb_args;
	char		*cpy;
	char		**stock;
	t_num		*nums;
	t_flags		flags;
	int			count;	
}				t_args;

int			ft_printf(const char* str, ...)
{
	va_list		arg;
	t_args		args;
	
	args.count = 0;
	args.nb_args = count_percents(str);
	args.nums = (t_num*)malloc(sizeof(t_num) * (args.nb_args + 1));
	args.stock = (char**)malloc(sizeof(char*) * (args.nb_args + 2));
	if (args.nb_args){
		va_start(arg, str);
		while (args.count < args.nb_args) {
			args.cpy = ft_strchr(str, '%');
			args.stock[args.count] = ft_strsub(str, 0, args.cpy - str);
			args.flags = parse(args.cpy + 1);
			if (args.flags.star)
				args.flags.width = va_arg(arg, int);
			args.nums[args.count] = flags2print(arg, args.flags);
			if (args.cpy[args.flags.count] == '%')
				--args.nb_args;
			str = args.cpy + args.flags.count + 1;
			++args.count;
		}
		va_end(arg);
	}
	args.stock[args.count] = (char*)str;
	return (print(args.stock, args.nums, args.nb_args, str));
}
