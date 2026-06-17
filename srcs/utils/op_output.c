/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakamot <dnakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 00:00:00 by dnakamot          #+#    #+#             */
/*   Updated: 2026/06/17 00:00:00 by dnakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	*bench_mode(void)
{
	static int	mode;

	return (&mode);
}

void	op_print(const char *s)
{
	if (*bench_mode() == 0)
		ft_printf("%s", s);
}
