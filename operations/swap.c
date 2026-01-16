/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:08:26 by marberge          #+#    #+#             */
/*   Updated: 2026/01/16 16:06:13 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_node **head)
{
	t_stack_node	*node_a;
	t_stack_node	*node_b;

	if (!head || !*head || lstsize(*head) < 2)
		return ;
	node_a = *head;
	node_b = node_a->next;
	node_a->next = node_b->next;
	node_a->prev = node_b;
	node_b->next = *head;
	node_b->prev = NULL;
	if (node_a->next != NULL)
		node_a->next->prev = *head;
	*head = node_b;
	return ;
}

void	sa(t_stack_node **head)
{
	swap(head);
	ft_printf("sa\n");
	return ;
}

void	sb(t_stack_node **head)
{
	swap(head);
	ft_printf("sb\n");
	return ;
}

void	ss(t_stack_node **head_a, t_stack_node **head_b)
{
	swap(head_a);
	swap(head_b);
	ft_printf("ss\n");
	return ;
}
