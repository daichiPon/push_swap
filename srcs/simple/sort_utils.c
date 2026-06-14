/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsachie <hsachie@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 08:01:48 by hsachie           #+#    #+#             */
/*   Updated: 2026/06/10 21:04:32 by hsachie          ###   ########.fr       */
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

int	find_max_index(t_stack *a)
{
	t_node	*cur;
	int	max;
	int	idx;
	int i;

	cur = a->top;
	max = cur->value;
	idx = 0;
	i = 0;
	while (cur)
	{
		if (cur->value > max)
		{
			max = cur->value;
			idx = i;
		}
		cur = cur->next;
		i++;
	}
	return (idx);
}

void	rotate_to_max(t_stack *a, int max_idx, int size)
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