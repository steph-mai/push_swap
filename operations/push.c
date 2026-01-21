/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 08:55:24 by stmaire           #+#    #+#             */
/*   Updated: 2026/01/21 14:35:19 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*node_to_push;

	if (!src || !*src || !dest)
		return ;
	node_to_push = *src;
	*src = node_to_push->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (!*dest)
	{
		*dest = node_to_push;
		node_to_push->next = NULL;
	}
	else
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
	ft_printf(1, "pa\n");
	return ;
}

void	pb(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push(stack_b, stack_a);
	ft_printf(1, "pb\n");
	return ;
}
