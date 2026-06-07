/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakamotodaichi <nakamotodaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 07:36:42 by nakamotodai       #+#    #+#             */
/*   Updated: 2026/06/07 03:23:06 by nakamotodai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

int         ft_atoi(char *str);
t_node      *ft_lstnew(int value);
void        ft_lstadd_back(t_stack *a, t_node *node);
int         ft_strcmp(const char *s1, const char *s2);

#endif