/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakamot <dnakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 23:35:31 by nakamotodai       #+#    #+#             */
/*   Updated: 2026/05/30 19:38:35 by dnakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_putnbr_u(unsigned int n)
{
	int		count;
	int		check;
	char	c;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_u(n / 10);
	c = n % 10 + '0';
	check = write(1, &c, 1);
	if (check < 0)
		return (check);
	count++;
	return (count);
}
