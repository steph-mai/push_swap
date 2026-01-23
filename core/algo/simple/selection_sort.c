/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 09:11:56 by stmaire           #+#    #+#             */
/*   Updated: 2026/01/23 10:41:07 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_min_to_top(t_stack **a, t_bench *bench, int size)
{
	t_stack	*min_node;
	int		position;

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
}

void	selection_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	size;

	size = lstsize(*a);
	if (size == 2)
	{
		if ((*a)->index > (*a)->next->index)
			sa(a, bench);
		return ;
	}
	while (size > 3)
	{
		move_min_to_top(a, bench, size);
		pb(a, b, bench);
		size--;
	}
	three_sort(a, bench);
	while (*b)
		pa(a, b, bench);
}
