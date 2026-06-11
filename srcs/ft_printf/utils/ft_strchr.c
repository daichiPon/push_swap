/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakamotodaichi <nakamotodaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 16:16:05 by nakamotodai       #+#    #+#             */
/*   Updated: 2026/06/12 06:00:13 by nakamotodai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

const char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return (s);
}

// int main(void)
// {
//     const char s[]="mojir%etu";
//     const char *res;
//     int c='%';
//     res=ft_strchr(s,c);
//     ft_printf("\n%s",res);
// }