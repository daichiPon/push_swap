/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakamot <dnakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 09:50:12 by nakamotodai       #+#    #+#             */
/*   Updated: 2026/05/31 14:49:48 by dnakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(char format, va_list *args)
{
	if (format == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (format == 'u')
		return (ft_putnbr_u(va_arg(*args, unsigned int)));
	else if (format == 'x')
		return (ft_puthex_lit(va_arg(*args, unsigned int)));
	else if (format == 'X')
		return (ft_puthex_big(va_arg(*args, unsigned int)));
	else if (format == 'p')
		return (ft_puthex_p(va_arg(*args, void *)));
	else if (format == '%')
		return (ft_putchar('%'));
	return (-1);
}
