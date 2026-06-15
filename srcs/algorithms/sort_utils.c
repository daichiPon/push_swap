/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakamot <dnakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 08:01:48 by hsachie           #+#    #+#             */
/*   Updated: 2026/06/15 21:11:31 by dnakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	sort_three_cases(a, a->top->value, a->top->next->value,
		a->top->next->next->value);
}
