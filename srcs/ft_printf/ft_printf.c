/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakamotodaichi <nakamotodaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 04:07:23 by nakamotodai       #+#    #+#             */
/*   Updated: 2026/06/12 06:00:13 by nakamotodai      ###   ########.fr       */
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

static int	parse_float(const char **format, va_list *args)
{
	int	prec;

	prec = 6;
	if (**format == '.')
	{
		(*format)++;
		prec = 0;
		while (**format >= '0' && **format <= '9')
			prec = prec * 10 + *(*format)++ - '0';
	}
	if (**format != 'f')
		return (-1);
	return (ft_putfloat(va_arg(*args, double), prec));
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
			format++;
			if (*format == '.' || *format == 'f')
				res = parse_float(&format, &args);
			else
				res = check_format(*format, &args);
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

// int main(void)
// {
//     int d;
//     d=1002;
//     ft_printf(" %c %c %c ", '0', 0, '1');
//     ft_printf("\n本物-%dだよ",d);
// }