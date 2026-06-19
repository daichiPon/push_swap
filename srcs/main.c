/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakamot <dnakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 20:55:13 by nakamotodai       #+#    #+#             */
/*   Updated: 2026/06/19 22:07:14 by dnakamot         ###   ########.fr       */
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

void	run_sort(t_stack *a, t_stack *b, int flag, double res)
{
	if (res == 0)
		return ;
	if (flag == 4)
		complex(a, b);
	else if (flag == 3)
		medium_sort(a, b);
	else if (flag == 2)
		simple_sort(a, b);
	else if (flag == 1)
		sort_adaptive(a, b, res);
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
	run_sort(&a, &b, flag, res);
	if (bench)
		print_bench(res, flag);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
