/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:51:14 by marberge          #+#    #+#             */
/*   Updated: 2026/01/21 14:27:44 by stmaire          ###   ########.fr       */
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

void	ra(t_stack_node **a, t_bench *bench)
{
	rotate(a);
	ft_printf("ra\n");
	if (bench && bench->active == 1)
	{
		bench->ra++;
		bench->total_count++;
	}
	return ;
}

void	rb(t_stack_node **b, t_bench *bench)
{
	rotate(b);
	ft_printf("rb\n");
	if (bench && bench->active == 1)
	{
		bench->rb++;
		bench->total_count++;
	}
	return ;
}

void	rr(t_stack_node **a, t_stack_node **b, t_bench *bench)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
	if (bench && bench->active == 1)
	{
		bench->rr++;
		bench->total_count++;
	}
	return ;
}
