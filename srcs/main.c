/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakamot <dnakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 20:55:13 by nakamotodai       #+#    #+#             */
/*   Updated: 2026/06/04 19:46:04 by dnakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

double compute_disorder(t_stack *a)
{
    size_t mistakes;
    size_t total_pairs;
    size_t i;
    size_t j;
    t_node *prev;
    t_node *cmp;

    mistakes = 0;
    total_pairs = 0;
    i = 0;
    prev = a -> top;
    while (i < a->size - 1)
    {
        j = i + 1;
        cmp = prev -> next;
        while (j < a->size)
        {
            total_pairs += 1;
            if ( prev->value > cmp->value)
                mistakes += 1;
            cmp=cmp->next;
            j++;
        }
        prev=prev->next;
        i++;
    }
    return ((double)mistakes / total_pairs);
}
void init_stack(t_stack *a ,int argc,char *argv[])
{
    int i;
    t_node *node;
    a->top =NULL;
    a->size =0;
    i = 1;
    while(i<argc)
    {
        node=ft_lstnew(ft_atoi(argv[i]));
        if(!node)
            return;
        ft_lstadd_back(a,node);
        i++;
    }
}

int main(int argc,char *argv[])
{
    t_stack a;
    double test;
    init_stack(&a,argc,argv);
    test=compute_disorder(&a);
    printf("%f",test);
}