/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:08:26 by marberge          #+#    #+#             */
/*   Updated: 2026/01/21 17:33:15 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **head)
{
	t_stack	*node_a;
	t_stack	*node_b;

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

void	sa(t_stack **head, t_bench *bench)
{
	swap(head);
	ft_printf("sa\n");
	if (bench && bench->active == 1)
	{
		bench->sa++;
		bench->total_count++;
	}
	return ;
}

void	sb(t_stack **head, t_bench *bench)
{
	swap(head);
	ft_printf("sb\n");
	if (bench && bench->active == 1)
	{
		bench->sb++;
		bench->total_count++;
	}
	return ;
}

void	ss(t_stack **head_a, t_stack **head_b, t_bench *bench)
{
	swap(head_a);
	swap(head_b);
	ft_printf("ss\n");
	if (bench && bench->active == 1)
	{
		bench->ss++;
		bench->total_count++;
	}
	return ;
}
