/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakamot <dnakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 18:40:25 by hsachie           #+#    #+#             */
/*   Updated: 2026/06/09 15:14:25 by dnakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *s)
{
	t_node	*tmp;
	t_node	*last;

	if (s->size <= 1)
		return ;
	tmp = s->top;
	s->top = s->top->next;
	s->top->prev = NULL;
	last = s->top;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->prev = last;
	tmp->next = NULL;
}
