/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:51:14 by marberge          #+#    #+#             */
/*   Updated: 2026/01/21 14:35:01 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack_node **head)
{
	t_stack_node	*head_temp;
	t_stack_node	*current_node;

	if (!head || !*head || lstsize(*head) < 2)
		return ;
	head_temp = *head;
	*head = head_temp->next;
	(*head)->prev = NULL;
	current_node = lstlast(*head);
	current_node->next = head_temp;
	head_temp->prev = current_node;
	head_temp->next = NULL;
}

void	ra(t_stack_node **a)
{
	rotate(a);
	ft_printf(1, "ra\n");
	return ;
}

void	rb(t_stack_node **b)
{
	rotate(b);
	ft_printf(1, "rb\n");
	return ;
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	ft_printf(1, "rr\n");
	return ;
}
