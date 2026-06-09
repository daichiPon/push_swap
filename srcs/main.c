/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakamot <dnakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 20:55:13 by nakamotodai       #+#    #+#             */
/*   Updated: 2026/06/10 03:18:59 by dnakamot         ###   ########.fr       */
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

	if (arg_check(argc, argv))
		return (write(1, "Error\n", 6));
	init_stack(&a, argc, argv);
	b.top = NULL;
	b.size = 0;
	res = compute_disorder(&a);
	printf("%f", res);
	fflush(stdout);
	complex(&a, &b);
	complex(&a, &b);
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
