/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:35:55 by stmaire           #+#    #+#             */
/*   Updated: 2026/01/21 11:34:18 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_algo(t_stack_node **a, t_stack_node **b)
{
	float	d;
	int		size;

	d = compute_disorder(*a);
	size = lstsize(*a);
	if (size < 20 || (size < 100 && (d < 0.3 || d >= 0.7)))
		selection_sort(a, b);
	else if (size < 2000 || (size < 4000 && d <= 0.6)
		|| (size < 10000 && d <= 0.2))
		range_based_sort(a, b);
	else
		radix_sort(a, b);
}
