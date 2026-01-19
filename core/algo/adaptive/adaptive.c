/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:35:55 by stmaire           #+#    #+#             */
/*   Updated: 2026/01/19 17:58:28 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void select_algo(t_stack_node **a,t_stack_node **b)
{
	float	disorder;
	int		size;

	disorder = compute_disorder(*a);
	size = lstsize(*a);
	if (size < 20)
		selection_sort(a,b);
	else if (size < 100)
	{
		if (disorder < 0.2)
			selection_sort(a,b);
		else
			range_based_sort(a, b);
	}
	else if (size < 1000)
			range_based_sort(a, b);
	else if (size < 5000)
	{
		if (disorder < 0.8)
			range_based_sort(a,b);
		else 
			radix_sort(a, b);
	}
	else if (size < 10000)
	{
		if (disorder < 0.2)
			range_based_sort(a,b);
		else 
			radix_sort(a, b);
	}
	else
		radix_sort(a, b);
}
