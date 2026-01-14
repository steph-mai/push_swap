/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:51:14 by marberge          #+#    #+#             */
/*   Updated: 2026/01/14 15:38:36 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	rotate(t_stack_node **head)
{
	t_stack_node	*head_temp;
	t_stack_node	*current_node;

	head_temp = *head;
	current_node = (*head)->next;
	head_temp->prev = NULL;
	current_node = lstlast(*head);
	current_node->next = *head;
	head_temp->prev = current_node;
	head_temp->next = NULL;
	*head = head_temp->next;
}