/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakamot <dnakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 22:58:29 by nakamotodai       #+#    #+#             */
/*   Updated: 2026/06/09 15:23:40 by dnakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_chunk_size(int n)
{
	int	i;

	i = 1;
	while (i * i < n)
		i++;
	return (i);
}

static int	find_max_pos(t_stack *b)
{
	t_node	*node;
	int		max_index;
	int		max_pos;
	int		pos;

	node = b->top;
	max_index = node->index;
	max_pos = 0;
	pos = 0;
	while (node)
	{
		if (node->index > max_index)
		{
			max_index = node->index;
			max_pos = pos;
		}
		node = node->next;
		pos++;
	}
	return (max_pos);
}

static void	push_chunk(t_stack *a, t_stack *b, int min, int max)
{
	int	mid;
	int	pushed;
	int	target;
	int	rotated;

	mid = (min + max) / 2;
	target = max - min + 1;
	pushed = 0;
	rotated = 0;
	while (pushed < target && rotated <= (int)a->size)
	{
		if (a->top->index >= min && a->top->index <= max)
		{
			pb(a, b);
			pushed++;
			rotated = 0;
			if (b->top->index <= mid)
				rb(b);
		}
		else
		{
			ra(a);
			rotated++;
		}
	}
}

static void	push_all_to_a(t_stack *a, t_stack *b)
{
	int	pos;
	int	size;

	while (b->size > 0)
	{
		pos = find_max_pos(b);
		size = (int)b->size;
		if (pos <= size / 2)
			while (pos-- > 0)
				rb(b);
		else
		{
			pos = size - pos;
			while (pos-- > 0)
				rrb(b);
		}
		pa(a, b);
	}
}

void	medium_sort(t_stack *a, t_stack *b)
{
	int	n;
	int	chunk_size;
	int	i;
	int	min;
	int	max;

	n = (int)a->size;
	chunk_size = ft_chunk_size(n);
	i = (n + chunk_size - 1) / chunk_size - 1;
	while (i >= 0)
	{
		min = i * chunk_size;
		max = min + chunk_size - 1;
		if (max >= n)
			max = n - 1;
		push_chunk(a, b, min, max);
		i--;
	}
	push_all_to_a(a, b);
}
