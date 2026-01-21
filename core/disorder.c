/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:08:11 by marberge          #+#    #+#             */
/*   Updated: 2026/01/21 18:00:45 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_stack *a, t_bench *bench)
{
	int		mistakes;
	int		total_pairs;
	t_stack	*temp_node_a;
	t_stack	*temp_node_b;
	float	result;

	if (!a || lstsize(a) < 2)
		return (00.00);
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
	result = (float)mistakes / (float)total_pairs * 100;
	if (bench)
		bench->disorder = result;
	return (result);
}
