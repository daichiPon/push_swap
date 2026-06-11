/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakamotodaichi <nakamotodaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 13:42:24 by hsachie           #+#    #+#             */
/*   Updated: 2026/06/12 06:00:13 by nakamotodai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
	ft_printf("ss\n");
}
