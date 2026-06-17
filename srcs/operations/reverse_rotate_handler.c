/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_handler.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakamotodaichi <nakamotodaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 18:57:47 by hsachie           #+#    #+#             */
/*   Updated: 2026/06/15 16:45:59 by nakamotodai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *s)
{
	t_node	*tmp;

	if (s->size <= 1)
		return ;
	tmp = s->top;
	while (tmp->next)
		tmp = tmp->next;
	tmp->prev->next = NULL;
	tmp->next = s->top;
	s->top->prev = tmp;
	s->top = tmp;
	s->top->prev = NULL;
}

void	rra(t_stack *a)
{
	reverse_rotate(a);
	op_count()->rra++;
	op_print("rra\n");
}

void	rrb(t_stack *b)
{
	reverse_rotate(b);
	op_count()->rrb++;
	op_print("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	op_count()->rrr++;
	op_print("rrr\n");
}
