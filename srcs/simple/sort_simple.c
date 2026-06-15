/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakamot <dnakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 21:56:10 by hsachie           #+#    #+#             */
/*   Updated: 2026/06/15 19:46:34 by dnakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void push_max_to_b(t_stack *a, t_stack *b, int *size)
{
    int min_idx;

    min_idx = find_min_index(a);
    rotate_to_min(a, min_idx, *size);
    pb(a, b);
    (*size)--;
}

void    simple_sort(t_stack *a, t_stack *b)
{
    int size;

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
