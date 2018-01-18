/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:42:30 by scornaz           #+#    #+#             */
/*   Updated: 2018/01/18 19:11:51 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_TYPES_H
# define PRINTF_TYPES_H

typedef struct	s_args {
	int			nb_args;
	char		*cpy;
	char		**stock;
	t_num		*nums;
	t_flags		flags;
	int			count;
}				t_args;

#endif
