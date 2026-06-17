/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakamot <dnakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 19:44:02 by hsachie           #+#    #+#             */
/*   Updated: 2026/06/18 05:48:10 by dnakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_stack *a, t_stack *b, double res)
{
	if (res < 0.2)
		simple_sort(a, b);
	else if (res < 0.5)
		medium_sort(a, b);
	else
		complex(a, b);
}
