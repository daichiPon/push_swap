/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakamot <dnakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 13:38:36 by hsachie           #+#    #+#             */
/*   Updated: 2026/06/09 15:15:27 by dnakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (b->size == 0)
		return ;
	tmp = b->top;
	b->top = b->top->next;
	if (b->top)
		b->top->prev = NULL;
	tmp->next = a->top;
	if (a->top)
		a->top->prev = tmp;
	tmp->prev = NULL;
	a->top = tmp;
	a->size++;
	b->size--;
	ft_printf("pa\n");
}
