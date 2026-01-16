/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:02:54 by marberge          #+#    #+#             */
/*   Updated: 2026/01/15 18:31:22 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void insertion_sort(t_stack_node **a, t_stack_node **b)
{
	t_stack_node *current_node;
	t_stack_node *lowest_index;

	pb(a, b);
	while (*a)
	{
		pb(a, b);
		while (compute_disorder(*b) != 1.00)
		{
			lowest_index = find_min(*b);
			current_node = *b;
			if (current_node->index < current_node->next->index && current_node != lowest_index)
				sb(b);
			else if (current_node->index > current_node->next->index)
				rb(b);
			else if (current_node->index < current_node->next->index && current_node == lowest_index)
			{
				rb(b);
				break;
			}
		}
	}
	while (*b)
		pa(a, b);
}
