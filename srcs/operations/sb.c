/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakamot <dnakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 11:57:22 by hsachie           #+#    #+#             */
/*   Updated: 2026/06/09 15:13:41 by dnakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sb(t_stack *b)
{
	int	tmp;

	if (b->size <= 1)
		return ;
	tmp = b->top->value;
	b->top->value = b->top->next->value;
	b->top->next->value = tmp;
	op_count()->sb++;
	printf("sb\n");
}
