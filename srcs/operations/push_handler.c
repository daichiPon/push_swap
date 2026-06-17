/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakamot <dnakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 13:38:36 by hsachie           #+#    #+#             */
/*   Updated: 2026/06/15 21:12:08 by dnakamot         ###   ########.fr       */
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
	op_count()->pa++;
	op_print("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (a->size == 0)
		return ;
	tmp = a->top;
	a->top = a->top->next;
	if (a->top)
		a->top->prev = NULL;
	tmp->next = b->top;
	if (b->top)
		b->top->prev = tmp;
	tmp->prev = NULL;
	b->top = tmp;
	a->size--;
	b->size++;
	op_count()->pb++;
	op_print("pb\n");
}
