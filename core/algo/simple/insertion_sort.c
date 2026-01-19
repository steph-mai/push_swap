/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:02:54 by marberge          #+#    #+#             */
/*   Updated: 2026/01/19 11:06:42 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void insertion_sort(t_stack_node **a, t_stack_node **b)
{
	t_stack_node *node;
	t_stack_node *lowest_index;

	pb(a, b);
	while (*a)
	{
		pb(a, b);
		while (compute_disorder(*b) != 1.00)
		{
			lowest_index = find_min(*b);
			node = *b;
			if (node->index < node->next->index && node != lowest_index)
				sb(b);
			else if (node->index > node->next->index)
				rb(b);
			else if (node->index < node->next->index && node == lowest_index)
			{
				rb(b);
				break;
			}
		}
	}
	while (*b)
		pa(a, b);
}
