/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakamotodaichi <nakamotodaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 21:30:47 by nakamotodai       #+#    #+#             */
/*   Updated: 2026/06/02 21:43:17 by nakamotodai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int ft_atoi(char *str)
{
    size_t i;
    int res;
    int sign;
    i=0;
    res=0;
    sign=1;
    if(str[i]=='-')
    {
        sign=-1;
        i++;
    }
    while(str[i])
    {
        res=res*10+str[i]-'0';
        i++;
    }
    return (res*sign);
}
