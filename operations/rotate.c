/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:51:14 by marberge          #+#    #+#             */
/*   Updated: 2026/01/14 16:06:22 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	rotate(t_stack_node **head)
{
	t_stack_node	*head_temp;
	t_stack_node	*current_node;

	head_temp = *head;
	*head = head_temp->next;
	(*head)->prev = NULL;
	current_node = lstlast(*head);
	current_node->next = head_temp;
	head_temp->prev = current_node;
	head_temp->next = NULL;
}