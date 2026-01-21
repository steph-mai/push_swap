/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:15:51 by marberge          #+#    #+#             */
/*   Updated: 2026/01/21 17:51:55 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int max_num)
{
	int	max_bits;

	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	sort_loop(t_stack **a, t_stack **b, int bit_max, t_bench *bench)
{
	int		i;
	int		k;
	t_stack	*current_node;
	int		len;

	i = 0;
	k = 0;
	len = lstsize(*a);
	while (i < bit_max)
	{
		while (k < len)
		{
			current_node = *a;
			if (((current_node->index >> i) & 1) == 1)
				ra(a, bench);
			else
				pb(a, b, bench);
			k++;
		}
		while (*b)
			pa(a, b, bench);
		i++;
		k = 0;
	}
}

void	radix_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int		bit_max;
	t_stack	*highest_index_node;

	highest_index_node = find_max(*a);
	bit_max = get_max_bits(highest_index_node->index);
	sort_loop(a, b, bit_max, bench);
}
