/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakamot <dnakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 19:44:02 by hsachie           #+#    #+#             */
/*   Updated: 2026/06/19 22:07:28 by dnakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_stack *a, t_stack *b, double res)
{
	if (a->size == 3)
		sort_three(a);
	else if (res < 0.2 || a->size <= 5)
		simple_sort(a, b);
	else if (res < 0.5)
		medium_sort(a, b);
	else
		complex(a, b);
}
