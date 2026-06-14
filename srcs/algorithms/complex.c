/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakamot <dnakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:26:57 by dnakamot          #+#    #+#             */
/*   Updated: 2026/06/10 03:21:45 by dnakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_btoa(t_stack *a, t_stack *b)
{
	while (b->size > 0)
		pa(a, b);
}

int	ft_max_value(t_stack *a)
{
	t_node	*node;
	int		max_value;

	max_value = 0;
	node = a->top;
	while (node)
	{
		if (node->index > max_value)
			max_value = node->index;
		node = node->next;
	}
	return (max_value);
}

int	ft_count_bit(t_stack *a)
{
	int	max_value;
	int	count;

	count = 0;
	max_value = ft_max_value(a);
	while (max_value)
	{
		max_value = max_value >> 1;
		count++;
	}
	return (count);
}

void	complex(t_stack *a, t_stack *b)
{
	int	bynary;
	int	i;
	int	count_bit;
	int	size;

	i = 0;
	count_bit = ft_count_bit(a);
	while (i < count_bit)
	{
		size = a->size;
		while (size > 0)
		{
			bynary = a->top->index >> i & 1;
			if (bynary == 0)
				pb(a, b);
			else
				ra(a);
			size--;
		}
		push_btoa(a, b);
		i++;
	}
}
