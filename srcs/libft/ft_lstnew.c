/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakamotodaichi <nakamotodaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 21:30:41 by nakamotodai       #+#    #+#             */
/*   Updated: 2026/06/07 03:25:16 by nakamotodai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
t_node *ft_lstnew(int value)
{
    t_node *node;
    node = malloc(sizeof(t_node));
    if(!node)
        return (NULL);
    node->value = value;
    node->index = 0;
    node->command = (t_command){0};
    node->prev = NULL;
    node->next = NULL;
    return node;
}