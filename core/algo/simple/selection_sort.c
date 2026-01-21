/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 09:11:56 by stmaire           #+#    #+#             */
/*   Updated: 2026/01/21 14:35:12 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selection_sort(t_stack_node **a, t_stack_node **b, t_bench *bench)
{
	int				size;
	t_stack_node	*min_node;
	int				position;

	size = lstsize(*a);
	while (size > 3)
	{
		min_node = find_min(*a);
		position = get_position(*a, min_node);
		if (position <= size / 2)
		{
			while (*a != min_node)
				ra(a, bench);
		}
		else
		{
			while (*a != min_node)
				rra(a, bench);
		}
		pb(a, b, bench);
		size--;
	}
	three_sort(a, bench);
	while (*b)
		pa(a, b, bench);
}
