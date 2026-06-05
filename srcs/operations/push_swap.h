/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsachie <hsachie@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 20:18:53 by nakamotodai       #+#    #+#             */
/*   Updated: 2026/06/05 14:22:54 by hsachie          ###   ########.fr       */
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

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
#endif