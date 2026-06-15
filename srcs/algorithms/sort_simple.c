/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakamot <dnakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 21:56:10 by hsachie           #+#    #+#             */
/*   Updated: 2026/06/15 21:12:33 by dnakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_min(t_stack *a, int max_idx, int size)
{
	if (max_idx <= size / 2)
	{
		while (max_idx > 0)
		{
			ra(a);
			max_idx--;
		}
	}
	else
	{
		while (max_idx < size)
		{
			rra(a);
			max_idx++;
		}
	}
}

int	find_min_index(t_stack *a)
{
	t_node	*cur;
	int		min;
	int		idx;
	int		i;

	cur = a->top;
	min = cur->value;
	idx = 0;
	i = 0;
	while (cur)
	{
		if (cur->value < min)
		{
			min = cur->value;
			idx = i;
		}
		cur = cur->next;
		i++;
	}
	return (idx);
}

static void	push_max_to_b(t_stack *a, t_stack *b, int *size)
{
	int	min_idx;

	min_idx = find_min_index(a);
	rotate_to_min(a, min_idx, *size);
	pb(a, b);
	(*size)--;
}

void	simple_sort(t_stack *a, t_stack *b)
{
	int	size;

	size = a->size;
	if (size == 2)
	{
		if (a->top->value > a->top->next->value)
			sa(a);
		return ;
	}
	if (size == 3)
	{
		sort_three(a);
		return ;
	}
	while (size > 3)
		push_max_to_b(a, b, &size);
	sort_three(a);
	while (b->top)
		pa(a, b);
}
