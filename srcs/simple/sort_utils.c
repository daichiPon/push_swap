/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakamot <dnakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 08:01:48 by hsachie           #+#    #+#             */
/*   Updated: 2026/06/15 19:49:58 by dnakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_node	*cur;

	cur = a->top;
	while (cur && cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}

int	find_min_index(t_stack *a)
{
	t_node	*cur;
	int	min;
	int	idx;
	int i;

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

static void	sort_three_cases(t_stack *a, int top, int mid, int bot)
{
	if (top > mid && mid < bot && top < bot)
		sa(a);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a);
		ra(a);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(a);
	else if (top < mid && mid > bot && top > bot)
		rra(a);
	else if (top > mid && mid > bot)
	{
		sa(a);
		rra(a);
	}
}

void	sort_three(t_stack *a)
{
	if (a->size < 2)
		return ;
	if (a->size == 2)
	{
		if (a->top->value > a->top->next->value)
			sa(a);
		return ;
	}
	sort_three_cases(a, a->top->value,
		a->top->next->value,
		a->top->next->next->value);
}