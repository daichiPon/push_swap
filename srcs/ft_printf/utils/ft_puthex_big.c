/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakamot <dnakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 00:01:32 by nakamotodai       #+#    #+#             */
/*   Updated: 2026/05/30 19:38:35 by dnakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_puthex_big(unsigned int n)
{
	int		count;
	int		check;
	char	*base;

	base = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count += ft_puthex_big(n / 16);
	check = write(1, &base[n % 16], 1);
	if (check < 0)
		return (check);
	count++;
	return (count);
}
