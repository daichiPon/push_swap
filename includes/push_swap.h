/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsachie <hsachie@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 20:18:53 by nakamotodai       #+#    #+#             */
/*   Updated: 2026/06/11 08:28:14 by hsachie          ###   ########.fr       */
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

void    pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void    ra(t_stack *a);
void	rb(t_stack *b);
void    reverse_rotate(t_stack *s);
void    rotate(t_stack *s);
void	rr(t_stack *a, t_stack *b);
void    rra(t_stack *a);
void    rrb(t_stack *b);
void    rrr(t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
static void push_max_to_b(t_stack *a, t_stack *b, int *size);
void    simple_sort(t_stack *a, t_stack *b);
static void	sort_three_cases(t_stack *a, int top, int mid, int bot);
void	sort_three(t_stack *a);
int     stack_size(t_stack *a);
int	is_sorted(t_stack *a);
int	find_max_index(t_stack *a);
void	rotate_to_max(t_stack *a, int max_idx, int size);

#endif