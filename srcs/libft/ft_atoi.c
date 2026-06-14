/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakamot <dnakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 21:30:47 by nakamotodai       #+#    #+#             */
/*   Updated: 2026/06/09 15:16:01 by dnakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_atoi(char *str)
{
	size_t	i;
	int		res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}
