/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakamot <dnakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 00:00:00 by dnakamot          #+#    #+#             */
/*   Updated: 2026/06/17 00:00:00 by dnakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	put_str_fd(const char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	write(fd, s, i);
}

void	put_nbr_fd(int n, int fd)
{
	char	c;

	if (n >= 10)
		put_nbr_fd(n / 10, fd);
	c = (char)('0' + n % 10);
	write(fd, &c, 1);
}

void	put_disorder_fd(double disorder, int fd)
{
	int	total;
	int	whole;
	int	frac;

	total = (int)(disorder * 10000.0 + 0.5);
	whole = total / 100;
	frac = total % 100;
	put_nbr_fd(whole, fd);
	write(fd, ".", 1);
	put_nbr_fd(frac / 10, fd);
	put_nbr_fd(frac % 10, fd);
	write(fd, "%", 1);
}

void	put_op(const char *label, int value)
{
	put_str_fd(label, 2);
	put_nbr_fd(value, 2);
	put_str_fd("  ", 2);
}
