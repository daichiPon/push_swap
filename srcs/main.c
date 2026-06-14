/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakamot <dnakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 20:55:13 by nakamotodai       #+#    #+#             */
/*   Updated: 2026/06/14 20:43:53 by dnakamot         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	double	res;
	t_node	*node;
	int		flag;
	int		bench;

	flag=0;
	bench=0;

	if (arg_check(argc, argv, &flag, &bench))
		return (write(1, "Error\n", 6));
	init_stack(&a, argc, argv);
	b.top = NULL;
	b.size = 0;
	res = compute_disorder(&a);
	if (flag == 4)
		complex(&a, &b);
	else if (flag == 3)
		medium_sort(&a, &b);
	else if (flag == 2)
		simple_sort(&a, &b);
	if (bench)
		print_bench(res, flag);
	node = a.top;
	while (node)
	{
		ft_printf("a: %d\n", node->value);
		node = node->next;
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
