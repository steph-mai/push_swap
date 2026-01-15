/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:02:54 by marberge          #+#    #+#             */
/*   Updated: 2026/01/15 17:50:47 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include <stdio.h>

void	insertion_sort(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*current_node;
	t_stack_node	*lowest_index;

	// current_node = *a;
	pb(a,b);
	while (*a)
	{
		pb(a,b);
		// current_node = *b;
		
		while (compute_disorder(*b) != 1.00) // le disorder mesure le taux de désordre de la liste. 1.00 = liste le moins triée possible et 0.00 = liste parfaitement trié
		{
			lowest_index = find_min(*b);
			current_node = *b;
			if (compute_disorder(*b) == 1.00)
				break ;
			if (current_node->index < current_node->next->index && current_node != lowest_index)
				sb(b);
			else if ( current_node->index > current_node->next->index)
				rb(b);
			else if (current_node->index < current_node->next->index && current_node == lowest_index)
			{
				rb(b);
				break ;
			}
			else
				break ;
		}
	}
	while (*b)
		pa(a,b);
}
