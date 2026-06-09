/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakamot <dnakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 03:47:07 by nakamotodai       #+#    #+#             */
/*   Updated: 2026/06/09 15:11:12 by dnakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

double	compute_disorder(t_stack *a)
{
	size_t	mistakes;
	size_t	total_pairs;
	size_t	i;
	size_t	j;
	t_node	*prev;
	t_node	*cmp;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	prev = a->top;
	while (i < a->size - 1)
	{
		j = i + 1;
		cmp = prev->next;
		while (j < a->size)
		{
			total_pairs += 1;
			if (prev->value > cmp->value)
				mistakes += 1;
			cmp = cmp->next;
			j++;
		}
		prev = prev->next;
		i++;
	}
	return ((double)mistakes / total_pairs);
}
