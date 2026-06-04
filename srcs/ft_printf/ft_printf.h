/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakamot <dnakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 04:11:41 by nakamotodai       #+#    #+#             */
/*   Updated: 2026/05/30 19:37:48 by dnakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "utils/utils.h"
# include <stdarg.h>
# include <stdio.h>

int	check_format(char format, va_list *args);
int	ft_printf(const char *format, ...);

#endif