/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:02:54 by marberge          #+#    #+#             */
/*   Updated: 2026/01/22 11:24:54 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack		*node;
	t_stack		*lowest_index;

	pb(a, b, bench);
	while (*a)
	{
		pb(a, b, bench);
		while (compute_disorder(*b) != 100.00)
		{
			lowest_index = find_min(*b);
			node = *b;
			if (node->index < node->next->index && node != lowest_index)
				sb(b, bench);
			else if (node->index > node->next->index)
				rb(b, bench);
			else if (node->index < node->next->index && node == lowest_index)
			{
				rb(b, bench);
				break ;
			}
		}
	}
	while (*b)
		pa(a, b, bench);
}
