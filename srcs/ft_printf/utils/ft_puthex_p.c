/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakamot <dnakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 08:54:16 by nakamotodai       #+#    #+#             */
/*   Updated: 2026/05/31 14:48:29 by dnakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	ft_puthex_addr(unsigned long n)
{
	int		count;
	int		check;
	char	*base;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_puthex_addr(n / 16);
	check = write(1, &base[n % 16], 1);
	if (check < 0)
		return (check);
	count++;
	return (count);
}

int	ft_puthex_p(void *n)
{
	int				count;
	int				check;
	int				res;
	unsigned long	addr;

	addr = (unsigned long)n;
	if (!n)
		return (write(1, "(nil)", 5));
	count = 0;
	check = write(1, "0x", 2);
	if (check < 0)
		return (check);
	count += 2;
	res = ft_puthex_addr(addr);
	if (res < 0)
		return (-1);
	count += res;
	return (count);
}

// int main(void)
// {
//     char n[]="moji";
//     ft_puthex_p(n);
//     return (0);
// }