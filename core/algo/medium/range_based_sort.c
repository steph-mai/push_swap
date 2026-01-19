/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_based_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 09:35:15 by stmaire           #+#    #+#             */
/*   Updated: 2026/01/19 11:23:22 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
		return (0);
	while (i * i <= nb)
		i++;
	return (i - 1);
}

static void	return_maxima_to_a(t_stack_node **a, t_stack_node **b)
{
	int				size;
	int				position;
	t_stack_node	*max_node;

	position = -1;
	if ((*b) == find_max(*b) || (*b)->index == ((find_max(*b)->index) - 1))
	{
		pa(a, b);
		if ((*a)->next != NULL && (*a)->index > (*a)->next->index)
			sa(a);
	}
	else
	{
		max_node = find_max(*b);
		position = get_position(*b, max_node);
		size = lstsize(*b);
		if (position < (size / 2))
			rb(b);
		else
		{
			while (*b != max_node)
				rrb(b);
		}
	}
}

void	range_based_sort(t_stack_node **a, t_stack_node **b)
{
	int			size;
	int			i;
	int			range;

	size = lstsize(*a);
	i = 0;
	range = ft_sqrt(size);
	while (*a)
	{
		if ((*a)->index >= 0 && (*a)->index < range + i)
		{
			pb(a, b);
			if ((*b)->index < i)
				rb(b);
			i++;
		}
		else
			ra(a);
	}
	while (*b)
		return_maxima_to_a(a, b);
}
