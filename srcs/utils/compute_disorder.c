/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakamot <dnakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 03:47:07 by nakamotodai       #+#    #+#             */
/*   Updated: 2026/06/09 15:49:21 by dnakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

double	compute_disorder(t_stack *a)
{
	size_t	mistakes;
	size_t	total_pairs;
	t_node	*prev;
	t_node	*cmp;

	mistakes = 0;
	total_pairs = 0;
	prev = a->top;
	while (prev && prev->next)
	{
		cmp = prev->next;
		while (cmp)
		{
			total_pairs += 1;
			if (prev->value > cmp->value)
				mistakes += 1;
			cmp = cmp->next;
		}
		prev = prev->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / total_pairs);
}
