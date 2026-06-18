/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakamotodaichi <nakamotodaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 19:44:02 by hsachie           #+#    #+#             */
/*   Updated: 2026/06/19 05:03:33 by nakamotodai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_stack *a, t_stack *b, double res)
{
	if(a->size == 3)
		sort_three(a);
	else if (res < 0.2 || a->size<= 5)
		simple_sort(a, b);
	else if (res < 0.5)
		medium_sort(a, b);
	else
		complex(a, b);
}
