/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakamotodaichi <nakamotodaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 20:18:53 by nakamotodai       #+#    #+#             */
/*   Updated: 2026/06/02 00:53:38 by nakamotodai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_P
#define PUSH_SWAP_P

#include <stdlib.h>
#include <stdio.h>

typedef struct s_command
{
   int  sa;
   int  sb;
   int  ss;
   int  pa;
   int  pb;
   int  ra;
   int  rb;
   int  rr;
   int  rra;
   int  rrb;
   int  rrr;
}   t_command;

typedef struct s_node
{
    int             value;
    int			index;
    t_command       command;
    struct s_node	*prev;
    struct s_node	*next;
} t_node;

typedef struct s_stack
{
    t_node  *top;
    size_t  size;
}   t_stack;

#endif