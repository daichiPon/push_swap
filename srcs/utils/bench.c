/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakamot <dnakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 00:00:00 by dnakamot          #+#    #+#             */
/*   Updated: 2026/06/16 20:35:12 by dnakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_command	*op_count(void)
{
	static t_command	count;

	return (&count);
}

static const char	*strategy_name(int flag, double disorder)
{
	if (flag == 4)
		return ("complex (radix sort, O(n log n))");
	if (flag == 3)
		return ("medium (chunk sort, O(n√n))");
	if (flag == 2)
		return ("simple (O(n^2))");
	if (disorder < 0.2)
		return ("adaptive (simple, O(n^2))");
	if (disorder < 0.5)
		return ("adaptive (medium, O(n√n))");
	return ("adaptive (complex, O(n log n))");
}

static int	total_ops(t_command *c)
{
	return (c->sa + c->sb + c->ss + c->pa + c->pb + c->ra
		+ c->rb + c->rr + c->rra + c->rrb + c->rrr);
}

static void	print_op_counts(t_command *c)
{
	put_line("sa: ", c->sa, 2);
	put_line("sb: ", c->sb, 2);
	put_line("ss: ", c->ss, 2);
	put_line("pa: ", c->pa, 2);
	put_line("pb: ", c->pb, 2);
	put_line("ra: ", c->ra, 2);
	put_line("rb: ", c->rb, 2);
	put_line("rr: ", c->rr, 2);
	put_line("rra: ", c->rra, 2);
	put_line("rrb: ", c->rrb, 2);
	put_line("rrr: ", c->rrr, 2);
}

void	print_bench(double disorder, int flag)
{
	t_command	*c;

	c = op_count();
	put_str_fd("Disorder: ", 2);
	put_disorder_fd(disorder, 2);
	put_str_fd("\nStrategy: ", 2);
	put_str_fd(strategy_name(flag, disorder), 2);
	put_str_fd("\nTotal operations: ", 2);
	put_nbr_fd(total_ops(c), 2);
	write(2, "\n", 1);
	print_op_counts(c);
}
