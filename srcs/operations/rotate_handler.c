/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakamotodaichi <nakamotodaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 21:40:27 by hsachie           #+#    #+#             */
/*   Updated: 2026/06/15 16:44:32 by nakamotodai      ###   ########.fr       */
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

void	ra(t_stack *a)
{
	rotate(a);
	op_count()->ra++;
	op_print("ra\n");
}

void	rb(t_stack *b)
{
	rotate(b);
	op_count()->rb++;
	op_print("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	op_count()->rr++;
	op_print("rr\n");
}
