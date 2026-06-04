/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakamot <dnakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 11:45:32 by nakamotodai       #+#    #+#             */
/*   Updated: 2026/05/30 19:38:35 by dnakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	ft_putstr(char *s)
{
	size_t	i;
	int		check;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		check = write(1, &s[i], 1);
		if (check < 0)
			return (check);
		i++;
	}
	return (i);
}
