/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakamot <dnakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 04:07:23 by nakamotodai       #+#    #+#             */
/*   Updated: 2026/06/15 21:17:49 by dnakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_res(int res, int *count)
{
	if (res < 0)
		return (-1);
	*count += res;
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		res;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			res = check_format(*++format, &args);
			if (check_res(res, &count) < 0)
				return (-1);
		}
		else
		{
			res = ft_putchar(*format);
			if (check_res(res, &count) < 0)
				return (-1);
		}
		format++;
	}
	va_end(args);
	return (count);
}
