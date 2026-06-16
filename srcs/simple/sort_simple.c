/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsachie <hsachie@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 21:56:10 by hsachie           #+#    #+#             */
/*   Updated: 2026/06/15 20:05:49 by hsachie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push_max_to_b(t_stack *a, t_stack *b, int *size)
{
    int max_idx;

    max_idx = find_max_index(a);
    rotate_to_max(a, max_idx, *size);
    pb(a, b);
    (*size)--;
}

void    simple_sort(t_stack *a, t_stack *b)
{
    int size;

    size = stack_size(a);
    if (size <= 1 || is_sorted(a))
        return ;
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