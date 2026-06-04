/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_lit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakamot <dnakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 23:52:32 by nakamotodai       #+#    #+#             */
/*   Updated: 2026/05/30 19:38:35 by dnakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_puthex_lit(unsigned int n)
{
	int		count;
	int		check;
	char	*base;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_puthex_lit(n / 16);
	check = write(1, &base[n % 16], 1);
	if (check < 0)
		return (check);
	count++;
	return (count);
}
