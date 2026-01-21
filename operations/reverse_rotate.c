/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:15:54 by marberge          #+#    #+#             */
/*   Updated: 2026/01/21 23:18:57 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **head)
{
	t_stack	*head_temp;
	t_stack	*current_node;

	if (!head || !*head || lstsize(*head) < 2)
		return ;
	head_temp = *head;
	current_node = lstlast(*head);
	*head = current_node;
	current_node->prev->next = NULL;
	current_node->next = head_temp;
	current_node->prev = NULL;
	head_temp->prev = current_node;
}

void	rra(t_stack **a, t_bench *bench)
{
	reverse_rotate(a);
	ft_printf(1, "rra\n");
	if (bench && bench->active == 1)
	{
		bench->rra++;
		bench->total_count++;
	}
	return ;
}

void	rrb(t_stack **b, t_bench *bench)
{
	reverse_rotate(b);
	ft_printf(1, "rrb\n");
	if (bench && bench->active == 1)
	{
		bench->rrb++;
		bench->total_count++;
	}
	return ;
}

void	rrr(t_stack **a, t_stack **b, t_bench *bench)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf(1, "rrr\n");
	if (bench && bench->active == 1)
	{
		bench->rrr++;
		bench->total_count++;
	}
	return ;
}
