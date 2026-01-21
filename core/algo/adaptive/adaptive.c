/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:35:55 by stmaire           #+#    #+#             */
/*   Updated: 2026/01/21 17:57:27 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_algo(t_stack **a, t_stack **b, t_bench *bench)
{
	float	d;
	int		size;

	d = compute_disorder(*a, bench);
	size = lstsize(*a);
	if (size < 20 || (size < 100 && (d < 30.00 || d >= 70.00)))
	{
		selection_sort(a, b, bench);
		bench->strategy = "simple";
	}
	else if (size < 2000 || (size < 4000 && d <= 60.00)
		|| (size < 10000 && d <= 20.00))
	{
		range_based_sort(a, b, bench);
		bench->strategy = "medium";
	}
	else
	{
		radix_sort(a, b, bench);
		bench->strategy = "complex";
	}
}
