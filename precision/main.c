/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 11:50:04 by scornaz           #+#    #+#             */
/*   Updated: 2018/01/27 14:47:19 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

#include <stdio.h>

void get_f(float a)
{
	unsigned aa;

	aa = *(int*)&a;
	int sign = (0x80000000 & aa) != 0;
	printf("sign %d\n", sign);
	unsigned mantisse = (aa % 0x10000000);
	printf("mantisse %d\n", mantisse);
	unsigned exp = (aa - mantisse) / 0x10000000;
	printf("exp %d\n", exp);

}

float		ft_pow(int base, int exp)
{
	float	ret;

	if (exp < 0)
		return (1 / ft_pow(base, -exp));
	ret = 1;
	while (exp-- > 0)
		ret *= base;
	return (ret);
}

int	main(void)
{
	float a = 0.15625;
	float b = 2.00456;
	int c = *(int*)&a;

	float sign = 1;
	int exp = 0;
	float mantisse = 1;
	for (int i = 31; i >= 0; i--)
	{
		if (i == 31 && (c & 1<<i) != 0)
			sign = -1;
		else if (i <= 30 && i >= 23 && ((c & 1<<i) != 0))
			exp += 1 << (i - 23);
		else if (i < 23 && (c & 1<<i) != 0)
			mantisse += ft_pow(2, i - 23);
//		printf("%d",  (c & 1<<i) != 0);
	}
	printf("%f %f %d %f \n", sign, mantisse, exp, ft_pow(10, exp - 127));
	printf("\n%f", sign * ft_pow(2, exp - 127) * mantisse);
//	get_f(a);
//	get_f(b);
}

