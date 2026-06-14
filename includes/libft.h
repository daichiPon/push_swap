/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakamot <dnakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 07:36:42 by nakamotodai       #+#    #+#             */
/*   Updated: 2026/06/10 21:20:51 by dnakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "push_swap.h"

int		ft_atoi(char *str);
t_node	*ft_lstnew(int value);
void	ft_lstadd_back(t_stack *a, t_node *node);
int		ft_strcmp(const char *s1, const char *s2);
int	    ft_strncmp(const char *s1, const char *s2, size_t n);

#endif