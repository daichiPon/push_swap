/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakamotodaichi <nakamotodaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 21:13:24 by hsachie           #+#    #+#             */
/*   Updated: 2026/06/15 16:42:07 by nakamotodai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sa(t_stack *a)
{
	int	tmp;

	if (a->size <= 1)
		return ;
	tmp = a->top->value;
	a->top->value = a->top->next->value;
	a->top->next->value = tmp;
	op_count()->sa++;
	op_print("sa\n");
}

void	sb(t_stack *b)
{
	int	tmp;

	if (b->size <= 1)
		return ;
	tmp = b->top->value;
	b->top->value = b->top->next->value;
	b->top->next->value = tmp;
	op_count()->sb++;
	op_print("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	int	tmp;

	if (a->size > 1)
	{
		tmp = a->top->value;
		a->top->value = a->top->next->value;
		a->top->next->value = tmp;
	}
	if (b->size > 1)
	{
		tmp = b->top->value;
		b->top->value = b->top->next->value;
		b->top->next->value = tmp;
	}
	op_count()->ss++;
	op_print("ss\n");
}
