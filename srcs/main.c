/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakamotodaichi <nakamotodaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 20:55:13 by nakamotodai       #+#    #+#             */
/*   Updated: 2026/06/07 03:59:12 by nakamotodai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/libft.h"


int main(int argc,char *argv[])
{
    t_stack a;
    double test;
    if(arg_check(argc,argv))
        return write(1,"Error\n",6);
    init_stack(&a,argc,argv);
    // main.c:185 付近を確認
    printf("size: %d\n", argc);
    printf("size: %zu\n", a.size);
    test=compute_disorder(&a);
    printf("%f",test);
}