/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 09:57:47 by stmaire           #+#    #+#             */
/*   Updated: 2026/01/22 11:26:08 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_stack **stack_a, t_bench *bench)
{
	t_stack	*node_one;
	t_stack	*node_two;
	t_stack	*node_three;

	if (!stack_a || !*stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
		return ;
	if (compute_disorder(*stack_a) == 0)
		return ;
	node_one = *stack_a;
	node_two = node_one->next;
	node_three = node_two->next;
	if (node_one->index > node_two->index
		&& node_one->index > node_three->index)
		ra(stack_a, bench);
	else if (node_two->index > node_one->index
		&& node_two->index > node_three->index)
		rra(stack_a, bench);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a, bench);
}
