/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakamot <dnakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 20:55:13 by nakamotodai       #+#    #+#             */
/*   Updated: 2026/06/17 21:30:43 by dnakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*next;

	node = stack->top;
	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
}

void	run_sort(t_stack *a, t_stack *b, int flag)
{
	if (flag == 4)
		complex(a, b);
	else if (flag == 3)
		medium_sort(a, b);
	else if (flag == 2)
		simple_sort(a, b);
	else if (flag == 1)
		sort_adaptive(a, b);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	double	res;
	int		flag;
	int		bench;

	flag = 0;
	bench = 0;
	if (arg_check(argc, argv, &flag, &bench))
		return (write(2, "Error\n", 6));
	init_stack(&a, &b, argc, argv);
	res = compute_disorder(&a);
	if (bench)
		*bench_mode() = 1;
	run_sort(&a, &b, flag);
	if (bench)
		print_bench(res, flag);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
