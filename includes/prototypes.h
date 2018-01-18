/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:52:48 by scornaz           #+#    #+#             */
/*   Updated: 2018/01/18 19:15:44 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "prototypes_ca.h"

int			ft_printf(const char *str, ...);
void		print_and_free(t_num **nums, char ***str, int *count);
void		hydrate(t_num *a, t_flags *flags);

#endif
