/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:52:48 by scornaz           #+#    #+#             */
/*   Updated: 2018/01/24 11:15:08 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "prototypes_ca.h"

t_num		flags2print(va_list arg, t_flags flags);
int			count_percents(const char *str);
void		init_args(t_args *args, const char *str);
int			ft_printf(const char *str, ...);
void		print_and_free(t_num **nums, char ***str, t_array *buffer);
void		hydrate(t_num *a, t_flags *flags);

#endif
