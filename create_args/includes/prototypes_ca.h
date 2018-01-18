/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes_ca.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:40:11 by scornaz           #+#    #+#             */
/*   Updated: 2018/01/18 19:05:11 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_CA_H
# define PROTOTYPES_CA_H

void	choose_itoa(char type, void *val, size_t *c);
void	itoa_base_dioux(unsigned int *i, size_t base, size_t *c);
void	parse_flags(char *str, t_num *a);
int		split_type(char *type, t_num *a);
int		parse_value(void *value, t_num *a);
void	print_alternate(t_num *type);
void	print_arg(t_num *num);
void	print_padding(size_t count, char with, size_t *c);
void	print_sign(int sign, size_t *c, char type, int space);
void	print_value(void *val, char type, size_t *c, size_t precision);
void	re_orga(t_num *a);
void	re_orga2(t_num *a);
void	ret_val(t_num *a, void *val);

#endif
