/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakamot <dnakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 03:59:23 by nakamotodai       #+#    #+#             */
/*   Updated: 2026/06/15 21:39:58 by dnakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include "../../includes/push_swap.h"

void	bubbl_sort(int *sort_arr, int n)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n - 1 - i)
		{
			if (sort_arr[j] > sort_arr[j + 1])
			{
				tmp = sort_arr[j + 1];
				sort_arr[j + 1] = sort_arr[j];
				sort_arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	add_index(int *sort_arr, t_stack *a, int n)
{
	int		i;
	t_node	*node;

	i = 0;
	while (i < n)
	{
		node = a->top;
		while (node)
		{
			if (sort_arr[i] == node->value)
			{
				node->index = i;
				break ;
			}
			node = node->next;
		}
		i++;
	}
}

void	init_index(t_stack *a)
{
	int		n;
	int		i;
	t_node	*node;
	int		*sort_arr;

	n = a->size;
	sort_arr = malloc(sizeof(int) * n);
	if (!sort_arr)
		return ;
	node = a->top;
	i = 0;
	while (i < n)
	{
		sort_arr[i] = node->value;
		node = node->next;
		i++;
	}
	bubbl_sort(sort_arr, n);
	add_index(sort_arr, a, n);
	free(sort_arr);
}

void	init_stack(t_stack *a, t_stack *b, int argc, char *argv[])
{
	int		i;
	t_node	*node;

	node = NULL;
	a->top = node;
	a->size = 0;
	b->top = NULL;
	b->size = 0;
	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--", 2) == 0)
		{
			i++;
			continue ;
		}
		node = ft_lstnew(ft_atoi(argv[i]));
		if (!node)
			return ;
		ft_lstadd_back(a, node);
		i++;
	}
	init_index(a);
}
