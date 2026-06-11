/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakamot <dnakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 00:00:00 by dnakamot          #+#    #+#             */
/*   Updated: 2026/06/12 00:00:00 by dnakamot         ###   ########.fr       */
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
	return ("adaptive");
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
	printf("Disorder: %.2f%%\n", disorder * 100);
	printf("Strategy: %s\n", strategy_name(flag));
	printf("Total operations: %d\n", total_ops(c));
	printf("sa: %d\n", c->sa);
	printf("sb: %d\n", c->sb);
	printf("ss: %d\n", c->ss);
	printf("pa: %d\n", c->pa);
	printf("pb: %d\n", c->pb);
	printf("ra: %d\n", c->ra);
	printf("rb: %d\n", c->rb);
	printf("rr: %d\n", c->rr);
	printf("rra: %d\n", c->rra);
	printf("rrb: %d\n", c->rrb);
	printf("rrr: %d\n", c->rrr);
}
