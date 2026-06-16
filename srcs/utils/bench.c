/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsachie <hsachie@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 00:00:00 by dnakamot          #+#    #+#             */
/*   Updated: 2026/06/16 19:32:14 by hsachie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_command	*op_count(void)
{
	static t_command	count;

	return (&count);
}

static const char	*strategy_name(int flag)
{
	if (flag == 4)
		return ("complex (radix sort, O(n log n))");
	if (flag == 3)
		return ("medium (chunk sort, O(n^2))");
	if (flag == 2)
		return ("simple (O(n^2))");
	if (flag == 1)
		return ("adaptive");
	return (NULL);
}

static int	total_ops(t_command *c)
{
	return (c->sa + c->sb + c->ss + c->pa + c->pb + c->ra
		+ c->rb + c->rr + c->rra + c->rrb + c->rrr);
}

void	print_bench(double disorder, int flag)
{
	t_command	*c;

	c = op_count();
	ft_printf("Disorder: %.2f%%\n", disorder * 100);
	ft_printf("Strategy: %s\n", strategy_name(flag));
	ft_printf("Total operations: %d\n", total_ops(c));
	ft_printf("sa: %d\n", c->sa);
	ft_printf("sb: %d\n", c->sb);
	ft_printf("ss: %d\n", c->ss);
	ft_printf("pa: %d\n", c->pa);
	ft_printf("pb: %d\n", c->pb);
	ft_printf("ra: %d\n", c->ra);
	ft_printf("rb: %d\n", c->rb);
	ft_printf("rr: %d\n", c->rr);
	ft_printf("rra: %d\n", c->rra);
	ft_printf("rrb: %d\n", c->rrb);
	ft_printf("rrr: %d\n", c->rrr);
}
