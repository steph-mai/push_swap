/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:08:11 by marberge          #+#    #+#             */
/*   Updated: 2026/01/15 16:04:28 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_stack_node *a)
{
	int				mistakes;
	int				total_pairs;
	t_stack_node	*temp_node_a;
	t_stack_node	*temp_node_b;

	// Pour gérer le cas ou la liste est nulle ou de longeur < a 2
	if (!a || lstsize(a) < 2)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	temp_node_a = a;
	while (temp_node_a->next != NULL)
	{
		temp_node_b = temp_node_a ->next;
		while (temp_node_b != NULL)
		{
			total_pairs++;
			if (temp_node_a->number > temp_node_b->number)
				mistakes++;
			temp_node_b = temp_node_b->next;
		}
		temp_node_a = temp_node_a->next;
	}
	return ((float)mistakes / (float)total_pairs);
}
