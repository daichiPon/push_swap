/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakamot <dnakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 20:18:53 by nakamotodai       #+#    #+#             */
/*   Updated: 2026/06/10 20:32:03 by dnakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_command
{
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
}					t_command;

typedef struct s_node
{
	int				value;
	int				index;
	t_command		command;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	size_t			size;
}					t_stack;

int					is_valid_number(char *str);
int					arg_check(int argc, char *argv[],int *flag,int *bench);
double				compute_disorder(t_stack *a);
t_command			*op_count(void);
void				print_bench(double disorder, int flag);
void				init_stack(t_stack *a, int argc, char *argv[]);
void				medium_sort(t_stack *a, t_stack *b);
void				complex(t_stack *a, t_stack *b);

void				rotate(t_stack *s);
void				reverse_rotate(t_stack *s);
void				pb(t_stack *a, t_stack *b);
void				pa(t_stack *a, t_stack *b);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);

#endif