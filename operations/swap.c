/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:08:26 by marberge          #+#    #+#             */
/*   Updated: 2026/01/13 19:11:33 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_node **head)
{
	t_stack_node	*node_a;
	t_stack_node	*node_b;

	// Si l'etiquette avec l adresse n 'existe pas OU si cette adresse est nulle OU si la liste contient - de 2 nodes
	if (!head || !*head || lstsize(*head) < 2)
		return ;
	node_a = *head;
	node_b = node_a->next;
	node_a->next = node_b->next;
	node_a->prev = node_b;
	node_b->next = *head;
	node_b->prev = NULL;
	// Si juste 2 node dans la liste on ne cherche pas a modifier un troisième qui n'existe pas (sinon segfault)
	if (node_a->next != NULL)
		node_a->next->prev = *head;
	*head = node_b;
	return ;
}
