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
		return ("Complex / O(n log n)");
	if (flag == 3)
		return ("Medium / O(n√n)");
	if (flag == 2)
		return ("Simple / O(n^2)");
	if (disorder < 0.2)
		return ("Adaptive / O(n^2)");
	if (disorder < 0.5)
		return ("Adaptive / O(n√n)");
	return ("Adaptive / O(n log n)");
}

static int	total_ops(t_command *c)
{
	return (c->sa + c->sb + c->ss + c->pa + c->pb + c->ra
		+ c->rb + c->rr + c->rra + c->rrb + c->rrr);
}

static void	print_op_counts(t_command *c)
{
	put_str_fd("[bench] ", 2);
	put_op("sa: ", c->sa);
	put_op("sb: ", c->sb);
	put_op("ss: ", c->ss);
	put_op("pa: ", c->pa);
	put_op("pb: ", c->pb);
	put_str_fd("\n[bench] ", 2);
	put_op("ra: ", c->ra);
	put_op("rb: ", c->rb);
	put_op("rr: ", c->rr);
	put_op("rra: ", c->rra);
	put_op("rrb: ", c->rrb);
	put_op("rrr: ", c->rrr);
	write(2, "\n", 1);
}

void	print_bench(double disorder, int flag)
{
	t_command	*c;

	c = op_count();
	put_str_fd("[bench] disorder: ", 2);
	put_disorder_fd(disorder, 2);
	put_str_fd("\n[bench] strategy: ", 2);
	put_str_fd(strategy_name(flag, disorder), 2);
	put_str_fd("\n[bench] total_ops: ", 2);
	put_nbr_fd(total_ops(c), 2);
	write(2, "\n", 1);
	print_op_counts(c);
}
