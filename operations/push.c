/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 08:55:24 by stmaire           #+#    #+#             */
/*   Updated: 2026/01/15 14:17:03 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*node_to_push;

	if (!src || !*src || !dest)
	//si une des stacks n'existe pas ou si src est vide
		return ;
	node_to_push = *src;
	*src = node_to_push->next;
	if (*src)
	//si le node_to_push n´était pas tout seul dans la stack src, le second node devient le premier
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (!*dest)
	//si dest était vide
	{
		*dest = node_to_push;
		node_to_push->next = NULL;
	}
	else
	//s'il y avait dejà des nodes dans dest
	//on modifie don next et son prev avant de modifier son adresse (pour ne pas la perdre)
	{
		node_to_push->next = *dest;
		(*dest)->prev = node_to_push;
		*dest = node_to_push;
	}
	return ;
}

void	pa(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa\n");
	return ;
}

void	pb(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pb\n");
	return ;
}
