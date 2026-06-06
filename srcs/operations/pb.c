/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsachie <hsachie@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:45:13 by hsachie           #+#    #+#             */
/*   Updated: 2026/06/05 17:10:23 by hsachie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *a, t_stack *b)
{
	t_node	*tmp;
	
	if (a->size == 0)
		return;
	tmp = a->top;
	a->top = a->top->next;
	if (a->top)
		a->top->prev = NULL;
	tmp->next = b->top;
	if (b->top)
		b->top->prev = tmp;
	tmp->prev = NULL;
	a->size--;
	b->size++;
	ft_printf("pb\n");
}