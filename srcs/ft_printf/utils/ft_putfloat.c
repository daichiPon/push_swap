/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakamotodaichi <nakamotodaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 00:00:00 by nakamotodai       #+#    #+#             */
/*   Updated: 2026/06/12 00:00:00 by nakamotodai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static double	rounding(int prec)
{
	double	r;

	r = 0.5;
	while (prec-- > 0)
		r /= 10.0;
	return (r);
}

static int	put_intpart(long long n)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count = put_intpart(n / 10);
		if (count < 0)
			return (-1);
	}
	if (ft_putchar('0' + n % 10) < 0)
		return (-1);
	return (count + 1);
}

static int	put_fracpart(double frac, int prec)
{
	int	count;
	int	digit;

	if (prec == 0)
		return (0);
	if (ft_putchar('.') < 0)
		return (-1);
	count = 1;
	while (prec-- > 0)
	{
		frac *= 10.0;
		digit = (int)frac;
		if (ft_putchar('0' + digit) < 0)
			return (-1);
		frac -= digit;
		count++;
	}
	return (count);
}

int	ft_putfloat(double n, int prec)
{
	int			count;
	int			res;
	long long	ipart;

	count = 0;
	if (n != n)
		return ((int)ft_putstr("nan"));
	if (n < 0)
	{
		if (ft_putchar('-') < 0)
			return (-1);
		count++;
		n = -n;
	}
	n += rounding(prec);
	ipart = (long long)n;
	res = put_intpart(ipart);
	if (res < 0)
		return (-1);
	count += res;
	res = put_fracpart(n - (double)ipart, prec);
	if (res < 0)
		return (-1);
	return (count + res);
}
