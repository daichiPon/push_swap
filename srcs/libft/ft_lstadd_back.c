/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakamotodaichi <nakamotodaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 21:40:14 by nakamotodai       #+#    #+#             */
/*   Updated: 2026/06/07 03:25:12 by nakamotodai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
void ft_lstadd_back(t_stack *a, t_node *node)
{
    t_node *tail;
    if(!node)
        return;
    if(!a->top)
    {
        a->top=node;
    }else{
        tail=a->top;
        while(tail->next)
            tail=tail->next;
        tail->next=node;
        node->prev=tail;
    }
    a->size++;
}