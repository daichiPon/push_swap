/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsachie <hsachie@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 18:47:36 by hsachie           #+#    #+#             */
/*   Updated: 2026/06/06 18:57:33 by hsachie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    reverse_rotate(t_stack *s)
{
	t_node	*tmp;
	
	if (s->size == 0)
		return;
	tmp = s->top;
	while(tmp->next)
		tmp = tmp->next;
	tmp->prev->next = NULL;
    tmp->next = s->top;
    s->top->prev = tmp;
    s->top = tmp;
    s->top->prev = NULL;
}