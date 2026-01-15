/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 09:57:47 by stmaire           #+#    #+#             */
/*   Updated: 2026/01/15 15:55:16 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_stack_node **stack_a)
{
	t_stack_node	*node_one;
	t_stack_node	*node_two;
	t_stack_node	*node_three;

	if (!stack_a || !*stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
		return ;
	if (compute_disorder(*stack_a) == 0)
		return ;
	node_one = *stack_a;
	node_two = node_one->next;
	node_three = node_two->next;
	if (node_one->index > node_two->index
		&& node_one->index > node_three->index)
		ra(stack_a);
	else if (node_two->index > node_one->index
		&& node_two->index > node_three->index)
		rra(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}
