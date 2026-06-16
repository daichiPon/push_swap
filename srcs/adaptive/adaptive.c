/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsachie <hsachie@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 19:44:02 by hsachie           #+#    #+#             */
/*   Updated: 2026/06/16 20:18:03 by hsachie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_stack *a, t_stack *b)
{
	double disorder_count;

	disorder_count = compute_disorder(a);
	if (disorder_count < 0.2)
		simple_sort(a, b);
	else if (disorder_count < 0.5)
		medium_sort(a, b);
	else
		complex(a, b);
}