/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:51:14 by marberge          #+#    #+#             */
/*   Updated: 2026/01/21 23:39:32 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **head)
{
	t_stack	*head_temp;
	t_stack	*current_node;

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

void	ra(t_stack **a, t_bench *bench)
{
	rotate(a);
	exec_and_count("ra", bench);
	return ;
}

void	rb(t_stack **b, t_bench *bench)
{
	rotate(b);
	exec_and_count("rb", bench);
	return ;
}

void	rr(t_stack **a, t_stack **b, t_bench *bench)
{
	rotate(a);
	rotate(b);
	exec_and_count("rrr", bench);
	return ;
}
