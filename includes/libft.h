/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakamotodaichi <nakamotodaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 07:36:42 by nakamotodai       #+#    #+#             */
/*   Updated: 2026/06/02 21:42:49 by nakamotodai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

int         ft_atoi(char *str);
t_node      *ft_lstnew(int value);
void        ft_lstadd_back(t_stack *a, t_node *node);

#endif